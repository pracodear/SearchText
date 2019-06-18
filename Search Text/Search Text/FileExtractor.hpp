//
//  FileExtractor.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 25/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef FileExtractor_hpp
#define FileExtractor_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

class FileExtractor
{
public:
    FileExtractor();
    ~FileExtractor();
    
    std::vector<std::string> readWords(std::istream&);
};

#endif /* FileExtractor_hpp */
