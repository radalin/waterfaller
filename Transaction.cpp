/* 
 * File:   Transaction.cpp
 * Author: roysimkes
 * 
 * Created on October 27, 2010, 11:34 PM
 */

#include "Transaction.h"
#include <stdio.h>

Transaction::Transaction(TransactionType type, int id, string data) {
    this->type = type;
    this->id = id;
    this->data = data;
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