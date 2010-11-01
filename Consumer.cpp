/* 
 * File:   Consumer.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include <sstream>

#include "Consumer.h"
#include "Buffer.h"
#include "Logger.h"
#include "Transaction.h"

Consumer::Consumer(int pid, int delay, int lifeSpan) {
    this->pid = pid;
    this->delay = delay;
    this->lifeSpan = lifeSpan;
    startTime = time(NULL);
}

Consumer::~Consumer() {
}

void Consumer::consume() {
    while ((startTime + lifeSpan) > time(NULL)) {
        this->readFromBuffer();
        sleep(delay);
    }
}

bool Consumer::readFromBuffer() {
    bool readSuccess = false;
    do {
        Transaction t("empty_data");
        readSuccess = Buffer::getInstance()->readFrom(t);
    } while (!readSuccess); //Try to write to buffer until it's available...
    return true;
}

