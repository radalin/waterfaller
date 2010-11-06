/* 
 * File:   App.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 4:03 PM
 */

#include <sstream>

#include "App.h"
#include "ConfigurationManager.h"
#include "Producer.h"
#include "Buffer.h"
#include "LogEvent.h"
#include "Logger.h"
#include "Consumer.h"

App::App() {
}

App* App::bootstrap() {
    conf = ConfigurationManager::getInstance();
    logger = Logger::getInstance();
    totalProcessCount = (conf->getIntConf("max_producer_count")
        + conf->getIntConf("max_consumer_count") + 1)
        * 10;
    pIdList = new pid_t[totalProcessCount];
    return this;
}

void App::run() {
    {
        LogEvent e("Application has begun", APPLICATION_BEGIN, getpid());
        logger->log(e);
    }
    //Start looping and create producers and consumers...
    this->createProducers();
    this->createConsumers();
    //Wait for children to finish...
    this->waitForChildren();
    if (!Buffer::getInstance()->isEmpty()) { //Check the buffer if it's empty or not...
        int remaining = Buffer::getInstance()->getCount();
        {
            stringstream message;
            message << "Buffer is not empty!" << "There are still " << remaining << "transactions to be consumed.";
            LogEvent e(message.str(), BUFFER_EMPTY, getpid());
            logger->log(e);
        }
        //Create the consumer according to the remaning transaction count...
        {
            LogEvent e("Consumer to consume remaining transactions is created", CONSUMER_CREATION, getpid());
            logger->log(e);
        }
        Consumer c(
            getpid(),
            conf->getIntConf("transaction_consumption_delay"),
             //Set the lifespan to consume all the remaining transactions accordingly...
            (remaining + 1) * conf->getIntConf("transaction_consumption_delay")
        );
        c.consume();
        {
            LogEvent e("Buffer is emptied", BUFFER_EMPTIED, getpid());
            logger->log(e);
        }
    }
    {
        LogEvent e("Application has ended", APPLICATION_END, getpid());
        logger->log(e);
    }
    //End of this cruel life...
}

void App::waitForChildren() {
    for (int i = 0; i < totalProcessCount; ++i) {
        if (pIdList[i] == NULL) {
            continue;
        }
        int status;
        while (-1 == waitpid(pIdList[i], &status, 0));
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            cout << "Process " << i << " (pid " << pIdList[i] << ") failed" << endl;
            exit(1);
        }
    }
}

void App::createProducers() {
    for (int i = 0 ; i < conf->getIntConf("max_producer_count") * 10; i += 10) {
        //fork and create producers...
        pIdList[i] = fork();
        if (pIdList[i] == 0) { //If this the child process...
            {
                LogEvent e("Producer created", PRODUCER_CREATION, getpid());
                logger->log(e);
            }
            Producer p(
                getpid(),
                conf->getIntConf("transaction_production_delay"),
                conf->getIntConf("producer_lifespan")
            );
            p.produce();
            exit(EXIT_SUCCESS); //End the lifecycle of the child process...
        }
    }
}

void App::createConsumers() {
    for (int i = 1 ; i < conf->getIntConf("max_consumer_count") * 10; i += 10) {
        //fork and create consumers...
        pIdList[i] = fork();
        if (pIdList[i] == 0) { //If this the child process...
            {
                LogEvent e("Consumer created", CONSUMER_CREATION, getpid());
                logger->log(e);
            }
            Consumer c(
                getpid(),
                conf->getIntConf("transaction_consumption_delay"),
                conf->getIntConf("consumer_lifespan")
            );
            c.consume();
            exit(EXIT_SUCCESS); //End the lifecycle of the child process...
        }
    }
}

App::~App() {
}