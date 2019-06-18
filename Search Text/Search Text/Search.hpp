//
//  Search.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 27/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Search_hpp
#define Search_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Search.hpp"
#include "Indexer.hpp"
#include "QuerySearch.hpp"
#include "IndexStore.hpp"

//Class that takes an IndexStore and returns a map with each query and file as key and count of occurence as the value
typedef std::pair<std::string, std::string> Key;
class Search
{
    std::unique_ptr<IndexStore> indexStore;
    std::map<Key, int> finalResult;
    std::vector<std::pair<std::string, int>> searchQueryWord(std::string, const std::vector<std::string>&);
    std::map<Key, int> searchAndQuery(const std::vector<std::string>&, const std::vector<std::string>&);
    void threadJob(const std::vector<std::string>&, const std::vector<std::string>&, int);
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Search";
public:
    Search(std::unique_ptr<IndexStore>);
    std::map<Key, int> searchQuery(const std::vector<std::vector<std::string>>&, const std::vector<std::string>&);
};

#endif /* Search_hpp */
