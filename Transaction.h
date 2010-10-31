/* 
 * File:   Transaction.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:34 PM
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

enum TransactionType {
    A,
    B
};

class Transaction {
public:
    Transaction(int t);
    virtual ~Transaction();
private:
    TransactionType type;
    
};

#endif	/* TRANSACTION_H */