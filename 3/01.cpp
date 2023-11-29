#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadLocal.h"
#include <iostream>

class HelloRunnable: public Poco::Runnable{
    virtual void run(){
        std::count << "Hello" << std::endl;
    }
};

class Counter: public Poco::Runnable {
    void run(){
        static Poco::ThreadLocal<int> tls;
        for (*tls = 0; *tls < 10; ++(*tls)){
            std::count << *tls << std::endl;
        }
    }
};

int main(int argc,char** argv){
    HelloRunnable runnable;
    Poco:: Thread thread;
    thread.start(runnable);
    thread.join();
    Counter counter1;
    Counter counter2;
    Poco:: Thread t2;
    Poco:: Thread t3;
    t2.start(counter1);
    t3.start(counter2);
    t2.join();
    t3.join();
    return 0;
}