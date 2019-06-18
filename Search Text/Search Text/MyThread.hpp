//
//  MyThread.hpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#ifndef MyThread_hpp
#define MyThread_hpp

#include <stdio.h>
#include <thread>
#include <mutex>

#define MAX_THREAD 10
class MyThreadPool;

class MyThread : public std::thread
{
    template<typename ...Types>
    MyThread(Types ... T);
public:
    friend MyThreadPool;
};

class MyThreadPool
{
    static int count;
    static std::mutex m;
public:
    template<typename... Types>
    MyThread& getThread(Types... f);
};

#endif /* MyThread_hpp */
