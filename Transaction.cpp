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
    {
        stringstream message;
        message << "Transaction is created with data: '" << this->getDataString() << "'";
        LogEvent e(message.str(), TRANSACTION_PRODUCTION, getpid());
        //Logger::getInstance()->log(e);
    }
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