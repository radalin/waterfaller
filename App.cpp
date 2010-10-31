/* 
 * File:   App.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 4:03 PM
 */

#include "App.h"
#include "ConfigurationManager.h"
#include "Producer.h"
#include "Buffer.h"
#include "LogEvent.h"
#include "Logger.h"

App::App() {
}

void App::run() {
    {
        LogEvent e("Application has begun", APPLICATION_BEGIN, 0);
        logger->log(e);
    }
    //Start looping and create producers and consumers...
    this->createProducers();
    this->createConsumers();
    //Wait for children to finish...
    if (!Buffer::getInstance()->isEmpty()) { //Check the buffer if it's empty or not...
        //Create another consumer with minimal delay and empty buffer...
    }
    {
        LogEvent e("Application has ended", APPLICATION_END, 0);
        logger->log(e);
    }
    //End of this cruel life...
}

void App::createProducers() {
    for (int i = 0 ; i < atoi(conf->getConf("max_producer_count").c_str()); i++) {
        //fork and create producers...
        {
            LogEvent e("Producer created", PRODUCER_CREATION, 0);
            logger->log(e);
        }
    }
}

void App::createConsumers() {
    for (int i = 0 ; i < atoi(conf->getConf("max_consumer_count").c_str()); i++) {
        //fork and create consumers...
    }
}

App* App::bootstrap() {
    conf = ConfigurationManager::getInstance();
    logger = Logger::getInstance();
    return this;
}

App::~App() {
}