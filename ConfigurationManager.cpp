/* 
 * File:   ConfigurationManager.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 12:22 AM
 */

#include "ConfigurationManager.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ConfigurationManager* ConfigurationManager::_instance = NULL;

ConfigurationManager::ConfigurationManager() {
    this->fileName = (char*) "conf.ini";
    this->openReadClose();
}

void ConfigurationManager::parse(string line) {
    if (!this->isCommentLine(line)) { //Only parse the uncommented lines...
        //TODO: Find out how to split the settings lines....
        size_t positionOfEqual;
        positionOfEqual = line.find('=');
        if (positionOfEqual == string::npos) {
            return; //Do not parse lines which does not have an equal sign...
        }
        string value(line.substr((int)positionOfEqual + 1));
        string key(line.substr(0, (int)positionOfEqual));
        //FIXME: I have to trim the values and keys as white spaces can cause problems...
        vector<string>::iterator it;
        //Append the keys...
        it = keys.begin();
        it = keys.insert (it, key);
        //Append the values...
        it = values.begin();
        it = values.insert (it, value);
    }
}

string ConfigurationManager::getConf(string key) {
    //Find the position for the key and return the value...
    int position = -1;
    for (int i = 0; position == -1; i++) {
        if (keys[i] == key) {
            position = i;
        }
    }
    if (position == -1) {
        throw "Invalid Configuration Parameter";
    }
    return values[position];
}

int ConfigurationManager::getIntConf(string key) {
    string s = this->getConf(key);
    return atoi(s.c_str());
}

float ConfigurationManager::getFloatConf(string key) {
    string s = this->getConf(key);
    return atof(s.c_str());
}

ConfigurationManager::~ConfigurationManager() {
}

ConfigurationManager* ConfigurationManager::getInstance() {
    if (!_instance) {
        _instance = new ConfigurationManager();
    }
    return _instance;
}