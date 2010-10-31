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
    Consumer();
    Transaction readFromBuffer();
    virtual ~Consumer();
private:

};

#endif	/* CONSUMER_H */

