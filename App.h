/* 
 * File:   App.h
 * Author: roysimkes
 *
 * Created on October 28, 2010, 4:03 PM
 */

#ifndef APP_H
#define	APP_H

#include "ConfigurationManager.h"
#include "Logger.h"


class App {
public:
    App();
    void run();
    App* bootstrap();
    virtual ~App();
    void createProducers();
    void createConsumers();
private:
    ConfigurationManager* conf;
    Logger* logger;
};

#endif	/* APP_H */

