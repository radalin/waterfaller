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
        //Create another consumer with minimal delay and empty buffer...
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
            Producer p(getpid(), conf->getIntConf("transaction_production_delay"), conf->getIntConf("producer_lifespan"));
            p.createTransactions();
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
            Consumer c(getpid(), 10);
            c.consume();
            exit(EXIT_SUCCESS); //End the lifecycle of the child process...
        }
    }
}

App::~App() {
}