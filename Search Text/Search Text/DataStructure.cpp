//
//  DataStructure.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "DataStructure.hpp"
#include "Trie.hpp"

//To get instance of DataStructure type object
DataStruct* DataStructFactory::getDataStructure(int i)
{
    DataStruct* ds = NULL;
    switch (i)
    {
        case 1:
            ds = new TrieTree();
            return ds;
    }
    return ds;
}
