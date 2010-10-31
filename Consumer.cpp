/* 
 * File:   Consumer.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include "Consumer.h"
#include "Buffer.h"

Consumer::Consumer() {
}

Consumer::~Consumer() {
}

Transaction Consumer::readFromBuffer() {
    return Buffer::getInstance()->readFrom();
}

