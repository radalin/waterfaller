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
    void writeTo(Transaction t);
    Transaction readFrom();
    bool isEmpty();
    bool isFull();
    static Buffer* getInstance();
private:
    Buffer();
    virtual ~Buffer();
    static Buffer* _instance;
};

#endif	/* BUFFER_H */

