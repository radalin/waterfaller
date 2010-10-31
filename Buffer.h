/* 
 * File:   Buffer.h
 * Author: roysimkes
 *
 * Created on October 31, 2010, 11:27 AM
 */

#ifndef BUFFER_H
#define	BUFFER_H

#include "FileReaderWriter.h"
#include "Transaction.h"


class Buffer: public FileReaderWriter {
public:
    bool writeTo(Transaction t);
    bool readFrom();
    bool isEmpty();
    bool isFull();
    bool isAvailable();
    static Buffer* getInstance();
private:
    Buffer();
    virtual ~Buffer();
    static Buffer* _instance;
    int limit;
    int count;
};

#endif	/* BUFFER_H */

