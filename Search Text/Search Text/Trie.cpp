//
//  Trie.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 24/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Trie.hpp"

TrieTreeNode::TrieTreeNode():isWord(false)
{
}

//Constructor to initialize the root of Trie
TrieTree::TrieTree() :root(getNode())
{
    log = Logger::getLoggerInstance();
}

//Destructor to delete the root node
TrieTree::~TrieTree()
{
    delete root;
}

//To create new node
TrieTreeNode * TrieTree::getNode()
{
    //It creates a new Trie node
    TrieTreeNode  *makeNode = new TrieTreeNode();
    return makeNode;
}

//To get private root
TrieTreeNode * TrieTree::getRoot()
{
    return root;
}

//To load words into Trie
bool TrieTree::load(const std::vector<std::string>& words)
{
    TrieTreeNode *crawler;
    TrieTreeNode *tmp;
    std::string current = "";
    for (int i=0;i<words.size();i++)
    {
        crawler = root;
        current = words[i];
        int len = (int)current.size();
        for (int j = 0; j < len; j++)
        {
            if (crawler->childMap.find(current[j]) == crawler->childMap.end())
            {
                crawler->childMap[current[j]] = tmp = getNode();
            }

            crawler = crawler->childMap[current[j]];
            
        }
        crawler->isWord = true;
        crawler->positions.push_back(i);
    }
    log->info(std::string(CLASS_TAG)+" Words loaded ");
    return true;
}

//To delete whole trie and create a new root
bool TrieTree::remove()
{
    root=deleteTrieHelper(root);
    log->info(std::string(CLASS_TAG)+" Tree deleted ");
    if (root == NULL)
    {
        //std::cout << "Dictionary deleted" << std::endl;
    }
    root = getNode();
    log->info(std::string(CLASS_TAG)+" New Root made ");
    return true;
}

//Helper function for deleting trie recursively
TrieTreeNode *TrieTree::deleteTrieHelper(TrieTreeNode *ptr)
{
    TrieTreeNode *crawler = ptr;
    std::map<char, TrieTreeNode *>::iterator it;
    if (crawler == NULL)
        return NULL;
    for (it = crawler->childMap.begin(); it != crawler->childMap.end(); it++)
    {
        crawler->childMap[it->first] = deleteTrieHelper(it->second);
    }
    delete(crawler);
    return NULL;
}

//To search a word in the Tree
std::set<int> TrieTree::search(std::string text)
{
    std::set<int> result;
    searchTrieRecHelper(root,result,0,text);
    log->info(std::string(CLASS_TAG)+" Search Completed ");
    return result;
}

//Helper function that takes a single word with any no. of "*" wildcards recursively and merge the position array of a qualified word in a result set
void TrieTree::searchTrieRecHelper(TrieTreeNode *crawler, std::set<int>& st, int index, std::string text)
{
    if(crawler == NULL)
    {
        return;
    }
    if(index == text.size())
    {
        if(crawler->isWord == true)
            std::copy( crawler->positions.begin(), crawler->positions.end(), std::inserter( st, st.end() ) );
        return;
    }
    else
    {
        if(text[index] != '*')
        {
            if (crawler->childMap.find(text[index]) != crawler->childMap.end())
                searchTrieRecHelper(crawler->childMap[text[index]], st, index+1, text);
            else
                return;
        }
        else
        {
            std::map<char, TrieTreeNode *>::iterator it;
            for (it = crawler->childMap.begin(); it != crawler->childMap.end(); it++)
            {
                searchTrieRecHelper(it->second, st, index, text);
            }
            searchTrieRecHelper(crawler, st, index+1, text);
        }
    }
}

//To copy a Trie and return its root
void TrieTree::copyDataStructure(DataStruct* ds)
{
    this->root = copyDataStructureHelper(static_cast<TrieTree*>(ds)->getRoot());
    log->info(std::string(CLASS_TAG)+" Tree copied ");
}

//Helper function to copy a Trie recursively
TrieTreeNode* TrieTree::copyDataStructureHelper(TrieTreeNode* crawler)
{
    if(crawler == NULL)
    {
        return crawler;
    }
    TrieTreeNode* temp = getNode();
    temp->isWord = crawler->isWord;
    temp->positions = crawler->positions;
    std::map<char, TrieTreeNode *>::iterator it;
    for (it = crawler->childMap.begin(); it != crawler->childMap.end(); it++)
    {
        temp->childMap[it->first] = copyDataStructureHelper(it->second);
    }
    return temp;
}

