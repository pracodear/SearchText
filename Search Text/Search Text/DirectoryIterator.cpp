//
//  DirectoryIterator.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "DirectoryIterator.hpp"

DirectoryIterator::DirectoryIterator(const char *  dir_path)
{
    log = Logger::getLoggerInstance();
    getAllTextFiles(dir_path);
}

void DirectoryIterator::getAllTextFiles(const char * dir_path)
{
    dirent * dir_element;
    DIR * dir = opendir(dir_path);
    
    try {
        if(dir == NULL)
            throw std::string(" Directory " +std::string(dir_path)+ " does not exist");
        while((dir_element = readdir(dir)))
        {
            char * dname = dir_element->d_name;
            char current_path[_POSIX_PATH_MAX] = {0};
            strcat(current_path, dir_path);
            strcat(current_path, OS_SEP);
            strcat(current_path, dname);
            char * abs_path = realpath(current_path, NULL);
            
            struct stat file_info;
            lstat(abs_path, &file_info);
            
            if(S_ISDIR(file_info.st_mode) == 1 && dname[0]!='.')
            {
                getAllTextFiles(abs_path);
            }
            else if(S_ISREG(file_info.st_mode) == 1)
            {
                std::string abs_path_str = std::string(abs_path);
                if(abs_path_str.find(".txt")!=std::string::npos)
                {
                    text_files.push_back(abs_path_str);
                }
                
            }
            
        }
    } catch (std::string msg) {
        log->error(std::string(CLASS_TAG)+msg);
    }
    log->info(std::string(CLASS_TAG)+" Successfully opened "+std::string(dir_path));
    closedir(dir);
    
}
void DirectoryIterator::setBegin()
{
    itr = text_files.begin();
}
bool DirectoryIterator::hasNext(){
    if(itr == text_files.end()){
        return false;
    }
    return true;
}

std::string DirectoryIterator::next(){
    std::string path =  *itr;
    itr++;
    return path;
}
