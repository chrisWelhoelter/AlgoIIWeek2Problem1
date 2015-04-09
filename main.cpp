//
//  main.cpp
//  AlgoIIWeek2Problem1
//
//  Created by Chris Welhoelter on 4/7/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Edge.h"
#include "QuickEdgeSorter.h"
#include "UnionFindSet.h"

int main(int argc, const char * argv[]) {
    
    std::string fileName;
    
    std::cout << "enter file name: ";
    std::cin >> fileName;
    std::cout << std::endl;
    
    std::fstream fs;
    fs.open(fileName);
    if (!fs.is_open()){
        std::cout << "could not open " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    
    size_t nodeCount;
    fs >> nodeCount;
    
    std::vector<Edge> edges;
    
    while (fs.good()){
        Edge newEdge;
        fs >> newEdge.node1;
        fs >> newEdge.node2;
        fs >> newEdge.cost;
        
        edges.push_back(newEdge);
    }
    
    // ***SORT***
    
    QuickEdgeSorter sorter;
    sorter.sort(edges, 0, (int)edges.size() - 1);
    
    //
    
    std::vector<UnionFindSet> connectedComponents(nodeCount + 1);
    
    size_t connectedComponentCount(nodeCount);
    size_t targetClusterCount;
    
    std::cout << "target number of clusters: ";
    std::cin >> targetClusterCount;
    std::cout << std::endl;
    
    size_t index = 0;
    while (connectedComponentCount > targetClusterCount){
        if (connectedComponents[edges[index].node1].headPointer != connectedComponents[edges[index].node2].headPointer){
            if (connectedComponents[edges[index].node1].headPointer->size >= connectedComponents[edges[index].node2].headPointer->size){
                connectedComponents[edges[index].node1].headPointer->setUnion(*connectedComponents[edges[index].node2].headPointer);
                connectedComponentCount--;
            }
            else {
                connectedComponents[edges[index].node2].headPointer->setUnion(*connectedComponents[edges[index].node1].headPointer);
                connectedComponentCount--;
            }
        }
        
        index++;
        
    }
    
    while (connectedComponents[edges[index].node1].headPointer == connectedComponents[edges[index].node2].headPointer){
        index++;
    }
    
    std::cout << "maximum spacing of " << targetClusterCount << "-clustering = " << edges[index].cost << std::endl;

    return 0;
}
