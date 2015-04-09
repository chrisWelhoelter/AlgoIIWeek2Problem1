//
//  UnionFindSet.h
//  AlgoIIWeek2Problem1
//
//  Created by Chris Welhoelter on 4/7/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#ifndef __AlgoIIWeek2Problem1__UnionFindSet__
#define __AlgoIIWeek2Problem1__UnionFindSet__

#include <stdio.h>

class UnionFindSet {
    
public:

    UnionFindSet* headPointer;
    UnionFindSet* nextPointer;
    UnionFindSet* tailPointer;
    size_t size;
    
    UnionFindSet();
    void setUnion(UnionFindSet set);
    
};

#endif /* defined(__AlgoIIWeek2Problem1__UnionFindSet__) */
