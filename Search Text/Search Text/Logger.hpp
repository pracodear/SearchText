//
//  Logger.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 28/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>

class Logger{
    static std::shared_ptr<Logger> instance;
    static std::string getCurrentTime();
    std::string logs;
    Logger();
public:
    ~Logger();
    void error(std::string str);
    void warn(std::string str);
    void log(std::string str);
    void info(std::string str);
    void debug(std::string str);
    static std::shared_ptr<Logger> getLoggerInstance();
};

#endif /* Logger_hpp */
