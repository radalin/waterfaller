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
    while ((startTime + lifeSpan) > time(NULL)) {
        Transaction t = this->createTransaction();
        {
            stringstream message;
            message << "Transaction is created with data: '" << t.getDataString() << "'";
            LogEvent e(message.str(), TRANSACTION_PRODUCTION, getpid());
            Logger::getInstance()->log(e);
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
        ss << "Z";
    }
    TransactionType type = TRANS_TYPE_A;
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 1) {
        type = TRANS_TYPE_B;
    }
    Transaction t(type, ++startingId, ss.str());
    return t;
}

bool Producer::writeToBuffer(Transaction t) {
    return Buffer::getInstance()->writeTo(t);
}

