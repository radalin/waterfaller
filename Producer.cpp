/* 
 * File:   Producer.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:31 PM
 */

#include "Producer.h"
#include "Transaction.h"
#include "Consumer.h"
#include "Logger.h"
#include "Buffer.h"

Producer::Producer(int delay) {
    delayTime = delay;
    LogEvent e("ali", PRODUCER_CREATION, 1);
    Logger::getInstance()->log(e);
}

Producer::~Producer() {
}

Transaction Producer::createTransaction() {
    Transaction t(12);
    return t;
}

void Producer::writeToBuffer(Transaction t) {
    Buffer::getInstance()->writeTo(t);
}

