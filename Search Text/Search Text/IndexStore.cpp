//
//  IndexStore.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "IndexStore.hpp"


//Private Constructor for IndexStore
IndexStore::IndexStore()
{
    log = Logger::getLoggerInstance();
}

//Public Destructor for IndexStore
IndexStore::~IndexStore()
{
    
}

//Thread function to create Indexer for each file
void IndexStore::loadFile(std::string filename, const std::vector<std::string>& fileWords)
{
    Indexer ind;
    ind.load(fileWords);
    log->info(std::string(CLASS_TAG)+" Load done for "+filename);
    index[filename] = ind;
}

//Creater indexer for each file via thread
void IndexStore::loadDir(std::string dir_path)
{
    DirectoryIterator di(dir_path.c_str());
    std::unique_ptr<Extractor> ex(new Extractor());
    std::vector<std::thread> threads;
    
    int dir_path_len = (unsigned)dir_path.length();
    di.setBegin();
    
    while(di.hasNext())
    {
        std::string fileName = di.next();
        std::ifstream file;
        try {
            file.open(fileName,std::fstream::in);
        } catch (std::ifstream::failure &e) {
            log->error(std::string(CLASS_TAG)+" Could not open "+fileName);
        }
        
        std::vector<std::string> fileWords;
        fileWords = ex->readWords(file);
        log->info(std::string(CLASS_TAG)+" Words extracted for "+fileName);
        file.close();
        threads.push_back(std::thread(&IndexStore::loadFile, this, fileName.substr(dir_path_len), fileWords));
    }
    for(auto& t: threads)
    {
        t.join();
    }
    log->info(std::string(CLASS_TAG)+" Directory "+std::string(dir_path)+" loaded");
}

//To set iterator of map to its begin
void IndexStore::setBegin()
{
    itr = index.begin();
}

//To check if map container has anymore elements
bool IndexStore::hasNext()
{
    if(itr == index.end())
    {
        return false;
    }
    return true;
}

//To move to next element of map container and return key of the Map
std::string IndexStore::next()
{
    std::string fileName =  itr->first;
    itr++;
    return fileName;
}

//To get Indexer for Filename
Indexer IndexStore::getIndexer(std::string s)
{
    return index[s];
}

std::unique_ptr<IndexStore>IndexStore:: instance(nullptr);
