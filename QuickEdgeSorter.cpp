//
//  QuickEdgeSorter.cpp
//  AlgoIIWeek2Problem1
//
//  Created by Chris Welhoelter on 4/7/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#include "QuickEdgeSorter.h"
#include <vector>
#include "Edge.h"

void QuickEdgeSorter::sort(std::vector<Edge> &edges, int left, int right){
    if (left < right) {
        int partitionPosition = partition(edges, left , right);
        sort(edges, left, partitionPosition - 1);
        sort(edges, partitionPosition + 1, right);
    }
}

int QuickEdgeSorter::partition(std::vector<Edge> &edges, int left, int right){
    
    int pivot = left;
    left++;
    
    while (left < right){
        while (edges[left].cost < edges[pivot].cost && left < right){
            left ++;
        }
        while (edges[right].cost > edges[pivot].cost && left < right){
            right--;
        }
        if (left < right){
            std::swap(edges[left], edges[right]);
            right--;
        }
    }
    
    if (edges[left].cost < edges[pivot].cost){
        std::swap(edges[pivot], edges[left]);
        return left;
    }
    
    if (edges[left - 1].cost < edges[pivot].cost){
        std:: swap(edges[pivot], edges[left - 1]);
        return left - 1;
    }
    
    else {
        return pivot;
    }
}



