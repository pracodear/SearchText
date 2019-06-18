//
//  FileExtractor.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "FileExtractor.hpp"


FileExtractor::FileExtractor()
{
    
}
FileExtractor::~FileExtractor()
{
    
}
std::vector<std::string> FileExtractor::readWords(std::istream& query)
{
    
    std::vector<std::string> words;
    std::string output;
    
    for(std::string output; query>>output;){
        
        std::string removed=",.?;\"";
        for (int i=0;i<removed.length();i++)
        {
            output.erase(std::remove(output.begin(), output.end(), removed[i]), output.end());
        }
        
        words.push_back(output);
    }
    return words;
}
