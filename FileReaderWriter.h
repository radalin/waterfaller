/* 
 * File:   FileReaderWriter.h
 * Author: roysimkes
 *
 * Created on October 30, 2010, 1:13 PM
 */

#ifndef FILEREADERWRITER_H
#define	FILEREADERWRITER_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileReaderWriter {
public:
    FileReaderWriter();
    void openReadClose();
    void append(string line);
    virtual ~FileReaderWriter();
protected:
    virtual void parse(string line);
    bool isCommentLine(string line);
    bool isNewLine(string c);
    ifstream fileStream;
    char* fileName;
};

#endif	/* FILEREADERWRITER_H */

