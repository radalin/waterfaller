/* 
 * File:   Logger.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:34 PM
 */

#ifndef LOGGER_H
#define	LOGGER_H
#include <string>
#include <iostream>

#include "LogEvent.h"


class Logger {
public:
    static Logger* getInstance();
    void log(string message);
    void log(LogEvent e);
private:
    Logger(){};
    virtual ~Logger(){};
    static Logger* _instance;
};

#endif	/* LOGGER_H */

