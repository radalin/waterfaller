/* 
 * File:   Consumer.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include "Consumer.h"
#include "Buffer.h"

Consumer::Consumer(int pid, int delay) {
    this->pid = pid;
    this->delay = delay;
}

Consumer::~Consumer() {
}

void Consumer::consume() {

}

void Consumer::readFromBuffer() {
    Buffer::getInstance()->readFrom();
}

