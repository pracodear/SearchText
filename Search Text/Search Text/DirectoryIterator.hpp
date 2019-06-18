//
//  DirectoryIterator.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef DirectoryIterator_hpp
#define DirectoryIterator_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>
#include <fstream>

#include "Logger.hpp"


#ifdef WIN32
#define OS_SEP "\\"
#else
#define OS_SEP "/"
#endif

#ifndef _POSIX_PATH_MAX
#define _POSIX_PATH_MAX  512
#endif

class DirectoryIterator
{
private:
    std::vector<std::string> text_files;
    void getAllTextFiles(const char *);
    std::vector<std::string>::iterator itr;
    std::shared_ptr<Logger> log;
    const std::string CLASS_TAG = "Directory Iterator";
    
public:
    
    DirectoryIterator(const char *);
    bool hasNext();
    std::string next();
    void setBegin();
};
#endif /* DirectoryIterator_hpp */
