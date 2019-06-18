//
//  Indexer.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Indexer.hpp"

void* Indexer::operator new(size_t size)
{
    return NULL;
}

//Constructor of Indexer to initialise DataStructure to a chosen implementation
Indexer::Indexer()
{
    log = Logger::getLoggerInstance();
    dsObject = DataStructFactory::getDataStructure(TRIE);
}

//Destructor of Indexer to clean DataStructure
Indexer::~Indexer()
{
    clean();
}

//Copy Constructor of Indexer
Indexer::Indexer(const Indexer& ind)
{
    this->dsObject = DataStructFactory::getDataStructure((ind.dsObject)->getType());
    this->dsObject->copyDataStructure(ind.dsObject);
    log->info(std::string(CLASS_TAG)+" DataStructure copied");
}

//Overload = operator of Indexer
Indexer& Indexer::operator=(const Indexer& ind)
{
    dsObject = DataStructFactory::getDataStructure((ind.dsObject)->getType());
    dsObject->copyDataStructure(ind.dsObject);
    log->info(std::string(CLASS_TAG)+" DataStructure copied");
    return *this;
}

//Load words into DataStructure
bool Indexer::load(const std::vector<std::string>& fileWords)
{
    clean();
    bool ret = dsObject->load(fileWords);
    log->info(std::string(CLASS_TAG)+" Word Load done");
    return ret;
}

//Clean whole DataStructure
bool Indexer::clean()
{
    bool ret = dsObject->remove();
    log->info(std::string(CLASS_TAG)+" DataStructure removed");
    return ret;
}

//Search in DataStructure
std::set<int> Indexer::search(std::string str)
{
    std::set<int> ret = dsObject->search(str);
    log->info(std::string(CLASS_TAG)+" DataStructure searched");
    return ret;
}


