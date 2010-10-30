/* 
 * File:   FileReaderWriter.cpp
 * Author: roysimkes
 * 
 * Created on October 30, 2010, 1:13 PM
 */

#include "FileReaderWriter.h"

FileReaderWriter::FileReaderWriter() {
}

void FileReaderWriter::openReadClose() {
    string line("");
    fileStream.open(fileName);
    if (fileStream.is_open()) {
        while (!fileStream.eof()) {
            getline(fileStream, line);
            this->parse(line);
        }
    }
    fileStream.close();
}

void FileReaderWriter::parse(string line) {
    //Do nothing, extended classes will override the use of this method...
}

bool FileReaderWriter::isCommentLine(string c) {
    size_t position;
    position = c.find(';');
    if (position != string::npos && (int) position == 0) {
        return true;
    }
    return false;
}

void FileReaderWriter::append(string line) {
    
}

FileReaderWriter::~FileReaderWriter() {
}

