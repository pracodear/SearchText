//
//  IndexStore.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef IndexStore_hpp
#define IndexStore_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "Indexer.hpp"
#include "Extractor.hpp"
#include "DirectoryIterator.hpp"
#include "MyThread.hpp"
#include "Logger.hpp"

//Class that acts as store for indexes of all .txt files
class IndexStore
{
private:
    //Pointer to store single instance of IndexStore
    static std::unique_ptr<IndexStore> instance;
    //Private map that contains index of each file
    std::map<std::string, Indexer> index;
    //Iterator to iterate through the above map
    std::map<std::string, Indexer>::iterator itr;
    void loadFile(std::string, const std::vector<std::string>&);
    IndexStore();
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "IndexStore";
    
public:
    ~IndexStore();
    void loadDir(std::string);
    bool hasNext();
    void setBegin();
    std::string next();
    Indexer getIndexer(std::string);
    
    //Static function to get instance of IndexStore
    static std::unique_ptr<IndexStore> getInstance()
    {
        if (instance == nullptr)
            instance.reset(new IndexStore);
        return std::move(instance);
    }
};

#endif /* IndexStore_hpp */
