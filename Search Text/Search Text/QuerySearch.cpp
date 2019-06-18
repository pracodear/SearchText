//
//  QuerySearch.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "QuerySearch.hpp"

//Constructor that takes in the indexer and the query that can contain many words 
QuerySearch::QuerySearch(const Indexer& ind,const std::string& s):ind(ind),query(s)
{
    log = Logger::getLoggerInstance();
}
QuerySearch::~QuerySearch()
{
    
}

//To seperate the words and delgate the final answer calculation to CalculateCount
int QuerySearch::getCount()
{
    std::unique_ptr<Extractor> ex(new Extractor());
    std::vector<std::string> queries;
    queries = ex->readWords(query);
    SearchResult sr;
    for(int i = 0; i<queries.size(); i++)
    {
        std::set<int> st = ind.search(queries[i]);
        std::vector<int> output(st.begin(),st.end());
        sr.insert(queries[i],output);
    }
    int ret = getCountHelper(sr);
    log->info(std::string(CLASS_TAG)+" Got count for "+query.str());
    return ret;
}
int QuerySearch::getCountHelper(SearchResult sr)
{
    sr.setBegin();
    std::vector<std::vector<int>> individualCount;
    while(sr.hasNext())
    {
        individualCount.push_back(sr.next());
    }
    CalculateCount cc(individualCount);
    return cc.getCount();
}
