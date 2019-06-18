//
//  Logger.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 28/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "Logger.hpp"

std::shared_ptr<Logger> Logger:: instance(nullptr);

Logger::Logger()
{
    
}

Logger::~Logger()
{
    
}

std::string Logger::getCurrentTime()
{
    std::time_t result = std::time(nullptr);
    return std::asctime(std::localtime(&result));
}

void Logger::error(std::string str)
{
    std::string message=getCurrentTime();
    message = message.substr(0, message.size()-1);
    message=message + " Error: ";
    message+=str;
    message+="\n";
    std::cout<<message<<std::endl;
    
}

void Logger::warn(std::string str)
{
    std::string message=getCurrentTime();
    message = message.substr(0, message.size()-1);
    message=message + " Warn: ";
    message+=str;
    message+="\n";
    std::cout<<message<<std::endl;
}

void Logger::debug(std::string str)
{
    std::string message=getCurrentTime();
    message = message.substr(0, message.size()-1);
    message=message + " Debug: ";
    message+=str;
    message+="\n";
    std::cout<<message<<std::endl;
    
}

void Logger::info(std::string str)
{
    std::string message=getCurrentTime();
    message = message.substr(0, message.size()-1);
    message=message + " Info: ";
    message+=str;
    message+="\n";
    std::cout<<message<<std::endl;
}

void Logger::log(std::string str)
{
    std::string message=getCurrentTime();
    message = message.substr(0, message.size()-1);
    message=message + " Log: ";
    message+=str;
    message+="\n";
    std::cout<<message<<std::endl;
}
std::shared_ptr<Logger> Logger::getLoggerInstance()
{
    if (instance == nullptr)
        instance.reset(new Logger());
    return instance;
    
}
