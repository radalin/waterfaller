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
    Producer(int pid, float delay, int lifeSpan);
    virtual ~Producer();
    Transaction createTransaction();
    void produce();
private:
    bool writeToBuffer(Transaction t);
    float delayTime;
    int pid;
    int lifeSpan;
    long startTime;
};

#endif	/* PRODUCER_H */

