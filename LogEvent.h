/* 
 * File:   LogEvent.h
 * Author: roysimkes
 *
 * Created on October 28, 2010, 12:28 AM
 */

#ifndef LOGEVENT_H
#define	LOGEVENT_H
#include <string>

using namespace std;

enum LogEventType {PRODUCER_CREATION, TRANSACTION_CREATION, CONSUMER_CREATION};

class LogEvent {
public:
    LogEvent(string message, LogEventType type, long pid);
    virtual ~LogEvent();
    string getMessage();
    LogEventType getType();
    long getPid();
private:
    string message;
    LogEventType type;
    long pid;
};

#endif	/* LOGEVENT_H */

