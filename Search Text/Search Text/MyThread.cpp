//
//  MyThread.cpp
//  Search Text
//
//  Created by Prakhar Mehrotra on 26/07/17.
//  Copyright © 2017 Prakhar Mehrotra. All rights reserved.
//

#include "MyThread.hpp"

template<typename ...Types>
MyThread::MyThread(Types ... T):thread(T...)
{
}

int MyThreadPool::count = MAX_THREAD;
std::mutex MyThreadPool::m;

template<typename... Types>
MyThread& MyThreadPool::getThread(Types... f)
{
    m.lock();
    if (count > 0)
    {
        MyThread *t = new MyThread(f...);
        count--;
        m.unlock();
        return (*t);
    }
    else
    {
        m.unlock();
        throw("Unable to Create Thread");
    }
}

