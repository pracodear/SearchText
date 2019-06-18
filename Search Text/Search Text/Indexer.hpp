//
//  Indexer.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Indexer_hpp
#define Indexer_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <set>

#include "DataStructure.hpp"
#include "SearchResult.hpp"
#include "Logger.hpp"

//Wrapper class for Data Structure to search through the file
class Indexer
{
private:
    //Overload new operator to private To prevent heap creation
    static void * operator new (size_t);
    DataStruct* dsObject;
    static const int TRIE=1;
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Indexer";
public:
    Indexer();
    ~Indexer();
    Indexer(const Indexer& ind);
    Indexer& operator=(const Indexer& ind);
    bool load(const std::vector<std::string>& fileWords);
    bool clean();
    void print();
    std::set<int> search(std::string str);
};


#endif /* Indexer_hpp */
