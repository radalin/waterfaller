/* 
 * File:   Buffer.cpp
 * Author: roysimkes
 * 
 * Created on October 31, 2010, 11:27 AM
 */

#include "Buffer.h"
#include "Transaction.h"
#include "ConfigurationManager.h"

Buffer* Buffer::_instance = NULL;

Buffer::Buffer() {
    this->fileName = (char*) "buffer.txt";
    limit = ConfigurationManager::getInstance()->getIntConf("buffer_limit");
    count = 0;
}

Buffer::~Buffer() {
}

Buffer* Buffer::getInstance() {
    if (!_instance) {
        _instance = new Buffer();
    }
    return _instance;
}

bool Buffer::readFrom() {
    if (this->isEmpty()) {
        return false;
    }
    count--;
    return true;
}

bool Buffer::writeTo(Transaction t) {
    if (this->isFull()) {
        return false;
    }
    count++;
    return true;
}

bool Buffer::isEmpty() {
    return count == 0;
}

bool Buffer::isFull() {
    return count == limit;
}