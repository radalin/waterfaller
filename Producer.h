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
    Producer(int delay);
    virtual ~Producer();
    Transaction createTransaction();
    void writeToBuffer(Transaction t);
private:
    int delayTime;
};

#endif	/* PRODUCER_H */

