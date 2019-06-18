//
//  InputParser.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef InputParser_hpp
#define InputParser_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Logger.hpp"

//Class to parse the input query.
class InputParser
{
private:
    std::string input;
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "InputParser";
public:
    InputParser(std::string);
    ~InputParser();
    std::vector<std::vector<std::string>> parse();
};
#endif /* InputParser_hpp */
