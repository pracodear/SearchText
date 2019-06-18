//
//  SearchResult.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "SearchResult.hpp"

//Constructor of a Search Result
SearchResult::SearchResult()
{
    
}
//Destructor of a Search Result
SearchResult::~SearchResult()
{
    
}


void SearchResult::print()
{
    itr = resList.begin();
    for (; itr != resList.end(); itr++)
    {
        std::cout << itr->first<<" : "<<std::endl;
        for(int i = 0; i < itr->second.size(); i++) {
            std::cout << itr->second[i]<<" "<<std::endl;
        }
    }
}

//Public function to insert into the private vector
void SearchResult::insert(const std::string& s,const std::vector<int>& pos)
{
    resList.push_back(make_pair(s,pos));
}

//To set iterator to beginning of private resList
void SearchResult::setBegin()
{
    itr = resList.begin();
}

//To check whether resList has a next element
bool SearchResult::hasNext(){
    if(itr == resList.end()){
        return false;
    }
    return true;
}

//To get next element from reList
std::vector<int> SearchResult::next()
{
    std::vector<int> positions =  itr->second;
    itr++;
    return positions;
}
