/* 
 * File:   Producer.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:31 PM
 */

#ifndef PRODUCER_H
#define	PRODUCER_H
#include "Transaction.h"

class Producer {
public:
    Producer(int pid, int delay);
    virtual ~Producer();
    Transaction createTransaction();
    void createTransactions();
private:
    void writeToBuffer(Transaction t);
    int delayTime;
    int pid;
};

#endif	/* PRODUCER_H */

