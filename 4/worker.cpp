#include "dispatcher.h"
#include "worker.h"
#include <chrono>

using namespace std;

void Worker::getCondition(condition_variable* &cv){
    cv = &(this)->cv;
}

void Worker::run(){
    while (running) {
        if (ready){
            ready = false;
            request->process();
            request->finish();
        }
        if (Dispatcher::addWorker(this)){
            while (!ready && running){
                if (cv.wait_for(ulock, chrono::seconds(1)) == cv_status::timeout){

                }
            }
        }
    }
}