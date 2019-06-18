//
//  SearchResult.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef SearchResult_hpp
#define SearchResult_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class SearchResult
{
private:
     //Vector to store the positions of all stomic queries. Used when a query with multiple subatomic queries comes up inside "".
     std::vector<std::pair<std::string, std::vector<int>>> resList;
     std::vector<std::pair<std::string, std::vector<int>>>::iterator itr;
public:
    SearchResult();
    ~SearchResult();
    void insert(const std::string&, const std::vector<int>&);
    bool hasNext();
    void setBegin();
    std::vector<int> next();
    void print();
};

#endif /* SearchResult_hpp */
