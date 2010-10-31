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
#include <sstream>

using namespace std;

Logger* Logger::_instance = NULL;

Logger::Logger() {
    this->fileName = (char *) "application.log";
}

Logger* Logger::getInstance() {
    if (!_instance) {
        _instance = new Logger();
    }
    return _instance;
}

void Logger::log(string message) {
    this->append(message);
}

void Logger::log(LogEvent e) {
    stringstream ss;
    ss<< "Logging Event wity type: '" << e.getType() << "' for pid: '"
        << e.getPid() << "' and execTime: '" << "' and with message: "
        << e.getMessage() ;
    this->log(ss.str());
}
