//
//  CalculateCount.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "CalculateCount.hpp"

//Constructor takes in a 2-D vector containing positions of each word in its 1-D vectors.
CalculateCount::CalculateCount(const std::vector <std::vector<int>>& b):B(b)
{
    
}
//Constructor
CalculateCount::~CalculateCount()
{
    
}

//To calculate the no. of times when
int CalculateCount::getCount()
{
    int count= (int)B[0].size();
    std::vector<int> temp; //copy the first row of input to temp
    temp = B[0];
    for(int j=1; j<B.size(); j++)
    {
        for(int i=0; i<temp.size(); i++)
        {
            std::vector <int>::iterator it = B[j].begin ();
            it = find (B[j].begin(), B[j].end(), temp[i]+1);
            if (it != B[j].end())
                temp[i]=temp[i]+1;
            else
            {
                temp.erase(temp.begin()+i);
                i--;
                count--;
            }
        }
    }
    return count;
}
