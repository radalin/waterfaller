/* 
 * File:   TransactionIdManager.h
 * Author: roysimkes
 *
 * Created on November 6, 2010, 2:08 PM
 */

#ifndef TRANSACTIONIDMANAGER_H
#define	TRANSACTIONIDMANAGER_H

#include "FileReaderWriter.h"


class TransactionIdManager: FileReaderWriter {
public:
    static TransactionIdManager* getInstance();
    int getNewId();
protected:
    void parse(string line);
private:
    TransactionIdManager();
    virtual ~TransactionIdManager();
    static TransactionIdManager* _instance;
    int lastId;
};

#endif	/* TRANSACTIONIDMANAGER_H */

