//
//  Output.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 28/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Output_hpp
#define Output_hpp

#include <stdio.h>

#include "IndexStore.hpp"
#include "Search.hpp"
#include "InputParser.hpp"
#include "Logger.hpp"

//Class to get Final Ouput of Search
class Output
{
private:
    std::unique_ptr<IndexStore> indexStore;
    std::vector<std::string> files;
    std::vector<std::string> atomicQueries;
    InputParser inputParser;
    std::map<Key, int> result;
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Output";

public:
    Output(std::unique_ptr<IndexStore>, InputParser);
    
    std::string getVerticalCollation();
    std::string getHorizontalCollation();
    void initialize();
};

#endif /* Output_hpp */
