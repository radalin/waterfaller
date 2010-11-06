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
        string data = this->readFromBuffer();
        this->consumeSingle(data);
        sleep(delay);
    }
}

void Consumer::consumeSingle(string data) {
    cout << data << "\n";
    if (data == "") {
        return;
    }
    Transaction t(data);
    {
        stringstream message;
        message << "Transaction is consumed with data: '" << t.getDataString() << "'";
        LogEvent e(message.str(), TRANSACTION_CONSUMPTION, getpid());
        Logger::getInstance()->log(e);
    }
}

string Consumer::readFromBuffer() {
    string data = "false";
    do {
        data = Buffer::getInstance()->readFrom();
    } while (data == "false"); //Try to write to buffer until it's available...
    return data;
}

