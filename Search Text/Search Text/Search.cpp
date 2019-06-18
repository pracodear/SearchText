//
//  Search.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 27/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Search.hpp"

//Constructor that takes the indexStore already created
Search::Search(std::unique_ptr<IndexStore> indexStore): indexStore(std::move(indexStore))
{
    log = Logger::getLoggerInstance();
}

//To get count for each query using QuerySearch object and return a vector containing pair of filename and count corresponding to it.
//Those files that return a 0 count are not used for the next query.
std::vector<std::pair<std::string, int>> Search::searchQueryWord(std::string query_word, const std::vector<std::string>& files)
{
    std::vector<std::pair<std::string, int>> result;
    for(std::string file : files)
    {
        QuerySearch qs(indexStore->getIndexer(file),query_word);
        int count = qs.getCount();
        if(count>0)
        {
            result.push_back(std::make_pair(file, count ));
        }
        
    }
    log->info(std::string(CLASS_TAG)+" Result calculated for && operator seperated string");
    return result;
}

//To get a map for each && seperated query corresponding a filename using vector of queries that are && seperated.
std::map<std::pair<std::string, std::string>, int> Search::searchAndQuery(const std::vector<std::string>& and_query, const std::vector<std::string>& files)
{
    std::map<Key, int> result;
    std::vector<std::string> searchFiles = files;
    std::vector<std::vector<std::pair<std::string, int>>> subquery_results;
    for(std::string query_word : and_query)
    {
        std::vector<std::pair<std::string, int>> subquery_result = searchQueryWord(query_word, searchFiles);
        searchFiles = std::vector<std::string>();
        for(std::pair<std::string, int> r : subquery_result)
        {
            searchFiles.push_back(r.first);
        }
        subquery_results.push_back(subquery_result);
    }
    
    
    int i = 0;
    for(std::vector<std::pair<std::string, int>> subquery_result : subquery_results)
    {
        for(std::pair<std::string, int> file_result : subquery_result)
        {
            if(std::find(searchFiles.begin(), searchFiles.end(),file_result.first)!=searchFiles.end())
            {
                Key k = std::make_pair(and_query[i], file_result.first);
                result.insert(std::make_pair(k, file_result.second));
            }
        }
        i++;
    }
    log->info(std::string(CLASS_TAG)+" Result calculated for || operator seperated string");
    return result;
}
//Inserting the final count of each && seperated query corresponding to a file in the private finalResult map
void Search::threadJob(const std::vector<std::string>& and_query, const std::vector<std::string>& files, int threadI)
{
    log->debug(std::string(CLASS_TAG)+" Thread "+std::to_string(threadI)+" created");
    std::map<Key, int> and_query_result = searchAndQuery(and_query, files);
    finalResult.insert(and_query_result.begin(), and_query_result.end());
    log->info(std::string(CLASS_TAG)+" Result inserted into the map");
}

//To throw threads for each vector of && operator seperated queries which are in turn seperated by || opertor
std::map<Key, int> Search::searchQuery(const std::vector<std::vector<std::string>>& query, const std::vector<std::string>& files){
    std::vector<std::thread> threads;
    int i = 0;
    for(std::vector<std::string> and_query : query)
    {
        i++;
        threads.push_back(std::thread(&Search::threadJob,this,and_query,files,i));
    }
    for (auto& th : threads)
    {
        th.join();
    }
    return finalResult;
}
