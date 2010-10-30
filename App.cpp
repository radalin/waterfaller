/* 
 * File:   App.cpp
 * Author: roysimkes
 * 
 * Created on October 28, 2010, 4:03 PM
 */

#include "App.h"
#include "ConfigurationManager.h"

App::App() {
}

void App::run() {
    cout << ConfigurationManager::getInstance()->getConf("foo") << "\n";
}

App* App::bootstrap() {
    ConfigurationManager::getInstance();
    return this;
}

App::~App() {
}

