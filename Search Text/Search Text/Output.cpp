
//
//  Output.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 28/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Output.hpp"

//Constructor taking InputParser and IndexStore
Output::Output(std::unique_ptr<IndexStore> indexStore, InputParser inputParser):indexStore(std::move(indexStore)),inputParser(inputParser)
{
    log = Logger::getLoggerInstance();
    initialize();
}

//To do all Search related work first and store it in a private map
void Output::initialize()
{
    indexStore->setBegin();
    while (indexStore->hasNext())
    {
        files.push_back(indexStore->next());
    }
    Search se(std::move(indexStore));
    std::vector<std::vector<std::string>> queries = inputParser.parse();
    std::vector<std::vector<std::string>>::iterator row;
    std::vector<std::string>::iterator col;
    for (row = queries.begin(); row != queries.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {
            atomicQueries.push_back(*col);
        }
    }
    result = se.searchQuery(queries, files);
    log->info(std::string(CLASS_TAG)+" initialized output");
}

//To return a string stream for VerticalCollation
std::string Output::getVerticalCollation()
{
    std::string str="";
    for(int i=0;i<files.size();i++)
    {
        for(int j=0;j<atomicQueries.size();j++)
        {
            if(result.find(make_pair(atomicQueries[j], files[i])) != result.end())
            {
                if(j==0)
                    str=str+files[i]+"\n";
                str=str + "\t" + atomicQueries[j] + ": " + std::to_string(result[make_pair(atomicQueries[j], files[i])])+"\n";
            }
        }
    }
    log->info(std::string(CLASS_TAG)+" Calculated Horizontal Collation");
    return str;
    
}

//To return a string stream for HorizontalCollation
std::string Output::getHorizontalCollation()
{
    std::string str="";
    for(int i=0;i<atomicQueries.size();i++)
    {
        for(int j=0;j<files.size();j++)
        {
            if(result.find(make_pair(atomicQueries[i], files[j])) != result.end())
            {
                if(j==0)
                    str=str+atomicQueries[i]+"\n";
                str=str + "\t" + files[j] + ": " + std::to_string(result[make_pair(atomicQueries[i], files[j])])+"\n";
            }
        }
    }
    log->info(std::string(CLASS_TAG)+" Calculated Vertical Collation");
    return str;
}
