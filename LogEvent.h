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

enum LogEventType {
    PRODUCER_CREATION,
    CONSUMER_CREATION,
    TRANSACTION_CONSUMPTION,
    TRANSACTION_PRODUCTION,
    APPLICATION_BEGIN,
    APPLICATION_END,
    ERROR
};

class LogEvent {
public:
    LogEvent(string message, LogEventType type, int pid);
    virtual ~LogEvent();
    string getMessage();
    LogEventType getType();
    int getPid();
private:
    string message;
    LogEventType type;
    int pid;
};

#endif	/* LOGEVENT_H */

