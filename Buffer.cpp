/* 
 * File:   Buffer.cpp
 * Author: roysimkes
 * 
 * Created on October 31, 2010, 11:27 AM
 */

#include <sstream>

#include "Buffer.h"
#include "Transaction.h"
#include "ConfigurationManager.h"
#include "Logger.h"

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
    return true;
}

bool Buffer::writeTo(Transaction t) {
    if (this->isFull()) {
        return false;
    }
    this->append(t.getDataString());
    stringstream m;
    m << "count of buffer: " << count++ << "\n";
    Logger::getInstance()->log(m.str());
    return true;
}

bool Buffer::isEmpty() {
    this->calculateBufferSize();
    return count == 0;
}

bool Buffer::isFull() {
    this->calculateBufferSize();
    return count == limit;
}

void Buffer::calculateBufferSize() {
    count = 0;
    this->openReadClose();
}

void Buffer::parse(string line) {
    count++;
}