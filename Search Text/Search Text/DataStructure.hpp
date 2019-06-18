//
//  DataStructure.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef DataStructure_hpp
#define DataStructure_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "SearchResult.hpp"

//Interface for any implementation of our Objective
class DataStruct
{
public:
    // To load the words into the DatStructure
    virtual bool load(const std::vector<std::string>&) = 0;
    // To delete a DatStructure
    virtual bool remove() = 0;
    //Search function to search an atomic query
    virtual std::set<int> search(std::string text) = 0;
    //To copy DataStructure
    virtual void copyDataStructure(DataStruct*) = 0;
    //To get Type of object in Factory
    virtual int getType() = 0;
};

//Factory for creating implementation of different algorithms
class DataStructFactory
{
public:
    static DataStruct* getDataStructure(int);
};

#endif /* DataStructure_hpp */
