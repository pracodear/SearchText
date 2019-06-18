//
//  Extractor.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 27/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Extractor_hpp
#define Extractor_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "Logger.hpp"

//A general extractor class for getting words from a file as well as for reading the input
class Extractor
{
private:
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Extractor";
public:
    Extractor();
    ~Extractor();
    
    std::vector<std::string> readWords(std::istream&);
};

#endif /* Extractor_hpp */
