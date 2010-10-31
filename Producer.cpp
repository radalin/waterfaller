/* 
 * File:   Producer.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:31 PM
 */

#include <sstream>
#include <stdio.h>

#include "Producer.h"
#include "Transaction.h"
#include "Consumer.h"
#include "Logger.h"
#include "Buffer.h"
#include "App.h"

Producer::Producer(int pid, float delay, int lifeSpan) {
    delayTime = delay;
    this->pid = pid;
    startTime = time(NULL);
    this->lifeSpan = lifeSpan;
    startingId = 0;
    LogEvent e("Producer is created", PRODUCER_CREATION, pid);
    Logger::getInstance()->log(e);
}

Producer::~Producer() {
}

void Producer::createTransactions() {
    Logger* l = Logger::getInstance();
    while ((startTime + lifeSpan) > time(NULL)) {
        Transaction t = this->createTransaction();
        {
            stringstream message;
            message << "Transaction is created with type: '" << t.getType()
                << "', id: '" << t.getId() << "' and data: '" << t.getData() << "'";
            LogEvent e(message.str(), TRANSACTION_PRODUCTION, getpid());
            //l->log(e);
        }
        bool writingSuccess = false;
        do {
            writingSuccess = this->writeToBuffer(t);
        } while (!writingSuccess); //Try to write to buffer until it's available...
        sleep(delayTime);
    }
}

Transaction Producer::createTransaction() {
    //Create data...
    stringstream ss;
    for (int i = 0; i < 95; i++) {
        ss << "z";
    }
    Transaction t(TRANS_TYPE_A, ++startingId, ss.str());
    return t;
}

bool Producer::writeToBuffer(Transaction t) {
    return Buffer::getInstance()->writeTo(t);
}

