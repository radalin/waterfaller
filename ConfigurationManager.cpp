/* 
 * File:   ConfigurationManager.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 12:22 AM
 */

#include "ConfigurationManager.h"
#include <stdlib.h>

ConfigurationManager* ConfigurationManager::_instance = NULL;

ConfigurationManager::ConfigurationManager() {
}

ConfigurationManager::~ConfigurationManager() {
}

ConfigurationManager* ConfigurationManager::getInstance() {
    if (_instance) {
        _instance = new ConfigurationManager();
    }
    return _instance;
}