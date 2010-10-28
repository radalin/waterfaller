/* 
 * File:   LogEvent.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 12:28 AM
 */

#include "LogEvent.h"

LogEvent::LogEvent(string message, LogEventType new_type, long new_pid) {
    this->message = message;
    type = new_type;
    pid = new_pid;
}

LogEvent::~LogEvent() {
}

//Getter and setters from now on
string LogEvent::getMessage() {
    return message;
}

long LogEvent::getPid() {
    return pid;
}

LogEventType LogEvent::getType() {
    return type;
}
