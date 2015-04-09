//
//  QuickEdgeSorter.h
//  AlgoIIWeek2Problem1
//
//  Created by Chris Welhoelter on 4/7/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#ifndef __AlgoIIWeek2Problem1__QuickEdgeSorter__
#define __AlgoIIWeek2Problem1__QuickEdgeSorter__

#include <stdio.h>
#include <vector>
#include "Edge.h"

class QuickEdgeSorter{
public:
    void sort(std::vector<Edge> &edges, int left, int right);
    int partition(std::vector<Edge> &edges, int left, int right);
};

#endif /* defined(__AlgoIIWeek2Problem1__QuickEdgeSorter__) */
