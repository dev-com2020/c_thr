#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "abstract_request.h"
#include <string>

using namespace std;

typedef void (*logFunction)(string text);


class Request : public AbstractRequest {
    
    int value;
    logFunction outFnc;
    
    public:
    void setValue(int value) {this->value = value; }
    void setOutput(logFunction fnc) {outFnc = fnc;}
    virtual void process();
    virtual void finish();
};
#endif