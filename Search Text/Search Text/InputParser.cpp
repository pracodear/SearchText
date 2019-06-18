//
//  InputParser.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "InputParser.hpp"

//Constructor that takes in the input string
InputParser::InputParser(std::string inp):input(inp)
{
    log = Logger::getLoggerInstance();
}
//Destructor
InputParser::~InputParser()
{
    
}

//To parse the input string
//and return a 2-D vector in which every 1-D vector contains all the AND seperated queries
//and every 1-D vector is made up of vectors seperated by OR operator
std::vector<std::vector<std::string>> InputParser::parse()
{
    std::string removed="\"";
    for (int i=0;i<removed.length();i++)
    {
        input.erase(std::remove(input.begin(), input.end(), removed[i]), input.end());
    }
    std::regex re1("\\|\\|");
    std::sregex_token_iterator itor(input.begin(), input.end(), re1, -1);
    std::sregex_token_iterator endor;
    std::vector <std::string> stringor;
    
    while (itor != endor)
    {
        stringor.push_back(*itor++);
    }
    
    
    std::vector <std::vector<std::string>> processedstring;
    for(int i=0;i<stringor.size();i++)
    {
        std::regex re2("&&");
        std::sregex_token_iterator itand(stringor[i].begin(), stringor[i].end(), re2, -1);
        std::sregex_token_iterator endand;
        
        std::vector<std::string> temp;
        while (itand != endand)
        {
            std::string value=*itand++;
            value.erase(value.begin(), std::find_if(value.begin(), value.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
            value.erase(std::find_if(value.rbegin(), value.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), value.end());
            temp.push_back(value);
        }
        processedstring.push_back(temp);
    }
    log->info(std::string(CLASS_TAG)+" input parsed");
    return processedstring;
}
