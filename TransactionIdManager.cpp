/* 
 * File:   TransactionIdManager.cpp
 * Author: roysimkes
 * 
 * Created on November 6, 2010, 2:08 PM
 */

#include "TransactionIdManager.h"
#include <sstream>

TransactionIdManager* TransactionIdManager::_instance = NULL;

TransactionIdManager::TransactionIdManager() {
    fileName = (char*) "transCount.txt";
    this->openReadClose();
}

TransactionIdManager::~TransactionIdManager() {
}

void TransactionIdManager::parse(string line) {
    if (line != "") {
        this->lastId = atoi(line.c_str());
    }
}

int TransactionIdManager::getNewId() {
    this->openReadClose();
    stringstream ss;
    ss << ++lastId;
    this->write(ss.str());
    return lastId;
}


TransactionIdManager* TransactionIdManager::getInstance() {
    if (!_instance) {
        _instance = new TransactionIdManager();
    }
    return _instance;
}

