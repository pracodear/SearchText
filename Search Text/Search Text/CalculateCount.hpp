//
//  CalculateCount.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef CalculateCount_hpp
#define CalculateCount_hpp

#include <stdio.h>
#include <vector>

//Class for calculating instances when words come together as in "". Deals with single words queries
class CalculateCount
{
private:
    std::vector<std::vector<int>> B;
public:
    CalculateCount(const std::vector<std::vector<int>>&);
    ~CalculateCount();
    
    int getCount();
};


#endif /* CalculateCount_hpp */
