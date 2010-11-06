/* 
 * File:   Buffer.cpp
 * Author: roysimkes
 * 
 * Created on October 31, 2010, 11:27 AM
 */

#include <sstream>

#include "Buffer.h"
#include "Transaction.h"
#include "ConfigurationManager.h"
#include "Logger.h"

Buffer* Buffer::_instance = NULL;

Buffer::Buffer() {
    this->fileName = (char*) "buffer.txt";
    limit = ConfigurationManager::getInstance()->getIntConf("buffer_limit");
    count = 0;
}

Buffer::~Buffer() {
}

Buffer* Buffer::getInstance() {
    if (!_instance) {
        _instance = new Buffer();
    }
    return _instance;
}

string Buffer::readFrom() {
    //FIXME: Bad implementation...
    if (this->isEmpty()) {
        return "false";
    }
    ifstream file;
    string line, dataString;
    stringstream content;
    bool isFirstLine = true;
    file.open(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            if (line == "") {
                continue;
            }
            if (isFirstLine) {
                isFirstLine = false;
                //TODO: This part causes a problem, I should fix it...
                dataString = line;
            } else {
                content << line << "\n";
            }
        }
    }
    file.close();
    ofstream output;
    output.open(fileName);
    output << content.str();
    output.close();
    return dataString;
}

bool Buffer::writeTo(Transaction t) {
    if (this->isFull()) {
        return false;
    }
    this->append(t.getDataString());
    return true;
}

bool Buffer::isEmpty() {
    this->calculateBufferSize();
    return count == 0;
}

bool Buffer::isFull() {
    this->calculateBufferSize();
    return count == limit;
}

void Buffer::calculateBufferSize() {
    count = 0;
    this->openReadClose();
}

int Buffer::getCount() {
    this->calculateBufferSize();
    return count;
}

void Buffer::parse(string line) {
    count++;
}