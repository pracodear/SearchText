//
//  QuerySearch.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef QuerySearch_hpp
#define QuerySearch_hpp

#include <stdio.h>
#include <string>
#include <sstream>

#include "Indexer.hpp"
#include "Extractor.hpp"
#include "CalculateCount.hpp"
#include "Logger.hpp"

//Class that takes as input the Indexer for a file and the query that can contain of many words without && or || operator
class QuerySearch
{
private:
    Indexer ind;
    std::istringstream query;
    int getCountHelper(SearchResult);
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Query Search";
public:
    QuerySearch(const Indexer&,const std::string&);
    ~QuerySearch();
    
    int getCount();
};

#endif /* QuerySearch_hpp */
