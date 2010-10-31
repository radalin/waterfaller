/* 
 * File:   Transaction.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:34 PM
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

#include <string>

using namespace std;

enum TransactionType {
    TRANS_TYPE_A,
    TRANS_TYPE_B
};

class Transaction {
public:
    Transaction(TransactionType type, int id, string data);
    virtual ~Transaction();
    TransactionType getType();
    int getId();
    string getData();
    string getDataString();
private:
    TransactionType type;
    int id;
    string data;
};

#endif	/* TRANSACTION_H */