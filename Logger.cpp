/* 
 * File:   Logger.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include "Logger.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

Logger* Logger::_instance = NULL;

Logger* Logger::getInstance() {
    if (!_instance) {
        _instance = new Logger();
    }
    return _instance;
}

void Logger::log(string message) {
    cout<<message<<"\n";
}

void Logger::log(LogEvent e) {
    //char* message;
    //sprintf(message, "Logging Event with type: %s with message:", e.getMessage());
    cout << e.getMessage() << " mesaj\n";
    //this->log(message);
}
