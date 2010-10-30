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
        vector<string>::iterator it;
        it = keys.begin();
        it = keys.insert (it, line);
        //cout << line << "size of vector: " << keys.size() << "\n";
    }
}

string ConfigurationManager::getConf(string key) {
    //Find the position for the key and return the value...
    
}

ConfigurationManager::~ConfigurationManager() {
}

ConfigurationManager* ConfigurationManager::getInstance() {
    if (!_instance) {
        _instance = new ConfigurationManager();
    }
    return _instance;
}