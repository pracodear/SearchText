//
//  Trie.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 24/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "DataStructure.hpp"
#include "Logger.hpp"

//Class for a node of Trie
class TrieTreeNode
{
public:
    std::map<char, TrieTreeNode *> childMap;
    bool isWord;
    std::vector <int> positions;// To store all the positions of a unique case insensitive word in the file
    TrieTreeNode();
};

//Class to apply different functions on
class TrieTree: public DataStruct
{
private:
    TrieTreeNode *root;
    TrieTreeNode *deleteTrieHelper(TrieTreeNode *);
    void searchTrieRecHelper(TrieTreeNode *, std::set<int>& , int, std::string);
    TrieTreeNode* copyDataStructureHelper(TrieTreeNode*);
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "TrieTree";
public:
    
    TrieTree();
    ~TrieTree();
    
    TrieTreeNode *getNode();
    
    //To load the words into the Trie
    bool load(const std::vector<std::string>&) override;
    
    //To delete a Trie
    bool remove() override;
    
    //Search function to search a text with length and output set of valid Words :-
    std::set<int> search(std::string) override;
    
    //To get Root
    TrieTreeNode* getRoot();
    
    //To Copy Tree exactly
    void copyDataStructure(DataStruct*) override;
    
    //To get Type of object
    int getType() override
    {
        return 1;
    }
    
};

#endif /* Trie_hpp */
