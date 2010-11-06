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

Transaction::Transaction(string dataString) {
    if (dataString == "") {
        throw "cannot initialize with empty string";
    }
    this->setWithDataString(dataString);
}

string Transaction::setWithDataString(string dataStr) {
    string idString = dataStr.substr(0, 4);
    stringstream ss;
    ss << std::hex << idString;
    ss >> this->id;
    this->type = (TransactionType) atoi(dataStr.substr(4, 1).c_str());
    this->data = dataStr.substr(5);
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