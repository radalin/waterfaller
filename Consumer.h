/* 
 * File:   Consumer.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:34 PM
 */

#ifndef CONSUMER_H
#define	CONSUMER_H

#include "Transaction.h"

class Consumer {
public:
    Consumer(int pid, int delay);
    virtual ~Consumer();
    void consume();
private:
    void readFromBuffer();
    int pid;
    int delay;
};

#endif	/* CONSUMER_H */

