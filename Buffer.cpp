/* 
 * File:   Buffer.cpp
 * Author: roysimkes
 * 
 * Created on October 31, 2010, 11:27 AM
 */

#include "Buffer.h"
#include "Transaction.h"

Buffer* Buffer::_instance = NULL;

Buffer::Buffer() {
    this->fileName = (char*) "buffer.txt";
}

Buffer::~Buffer() {
}

Buffer* Buffer::getInstance() {
    if (!_instance) {
        _instance = new Buffer();
    }
    return _instance;
}

Transaction Buffer::readFrom() {
    Transaction t(12);
    return t;
}

void Buffer::writeTo(Transaction t) {
    
}

bool Buffer::isEmpty() {
    return false;
}

bool Buffer::isFull() {
    return false;
}