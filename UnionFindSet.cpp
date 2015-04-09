//
//  UnionFindSet.cpp
//  AlgoIIWeek2Problem1
//
//  Created by Chris Welhoelter on 4/7/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#include "UnionFindSet.h"

UnionFindSet::UnionFindSet(){
    
    headPointer = this;
    nextPointer = nullptr;
    tailPointer = this;
    size = 1;
    
}
 
void UnionFindSet::setUnion(UnionFindSet set){
    
    size += set.size;
    set.size = 0;
    tailPointer->nextPointer = set.headPointer;
    tailPointer = set.tailPointer;
    set.tailPointer = nullptr;
    
    UnionFindSet* curPtr = set.headPointer;
    
    while (curPtr != nullptr){
        curPtr->headPointer = headPointer;
        curPtr = curPtr->nextPointer;
    }
}