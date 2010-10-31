/* 
 * File:   Consumer.h
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:34 PM
 */

#ifndef CONSUMER_H
#define	CONSUMER_H

#include "Transaction.h"
#include "FileReaderWriter.h"

class Consumer {
public:
    Consumer(int pid, int delay, int lifeSpan);
    virtual ~Consumer();
    void consume();
private:
    bool readFromBuffer();
    int pid;
    int delay;
    long startTime;
    int lifeSpan;
};

#endif	/* CONSUMER_H */

