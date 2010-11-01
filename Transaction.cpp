/* 
 * File:   Transaction.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include "Transaction.h"
#include "Logger.h"
#include <stdio.h>
#include <sstream>

Transaction::Transaction(TransactionType type, int id, string data) {
    this->type = type;
    this->id = id;
    this->data = data;
}

string Transaction::setWithDataString(string dataStr) {
    //FIXME: Parse data string and assign appriate values...
}

Transaction::~Transaction() {
}

TransactionType Transaction::getType() {
    return type;
}
int Transaction::getId() {
    return id;
}
string Transaction::getData() {
    return data;
}

string Transaction::getDataString() {
    char hexId[4];
    sprintf(hexId, "%04X", id);
    stringstream d;
    d << hexId << type << data;
    return d.str();
}