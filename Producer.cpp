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

Producer::Producer(int pid, int delay) {
    delayTime = delay;
    this->pid = pid;
    LogEvent e("Producer is created", PRODUCER_CREATION, pid);
    Logger::getInstance()->log(e);
}

Producer::~Producer() {
}

void Producer::createTransactions() {

}

Transaction Producer::createTransaction() {
}

void Producer::writeToBuffer(Transaction t) {
    Buffer::getInstance()->writeTo(t);
}

