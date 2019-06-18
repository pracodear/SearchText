//
//  Extractor.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 27/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Extractor.hpp"

//Constructor
Extractor::Extractor()
{
    log = Logger::getLoggerInstance();
}
//Destructor
Extractor::~Extractor()
{
    
}

//To extract words and return a vector of the words
//Removing words such as ;'? etc.
std::vector<std::string> Extractor::readWords(std::istream& query)
{
    
    std::vector<std::string> words;
    std::string output;
    
    for(std::string output; query>>output;){
        
        std::string removed=",.?;\"";
        for (int i=0;i<removed.length();i++)
        {
            output.erase(std::remove(output.begin(), output.end(), removed[i]), output.end());
        }
        std::transform(output.begin(), output.end(), output.begin(),(int (*)(int))tolower);
        words.push_back(output);
    }
    log->info(std::string(CLASS_TAG)+" Words extracted");
    return words;
}
