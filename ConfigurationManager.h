/* 
 * File:   ConfigurationManager.h
 * Author: roysimkes
 *
 * Created on October 28, 2010, 12:22 AM
 */

#ifndef CONFIGURATIONMANAGER_H
#define	CONFIGURATIONMANAGER_H

#include "FileReaderWriter.h"
#include <vector>


class ConfigurationManager: public FileReaderWriter {
public:
    static ConfigurationManager* getInstance();
    string getConf(string key);
    int getIntConf(string key);
    float getFloatConf(string key);
protected:
    virtual void parse(string line);
private:
    ConfigurationManager();
    virtual ~ConfigurationManager();
    static ConfigurationManager* _instance;
    //TODO: hash map is the right thing to do, not like this! This is sucks!!!
    vector<string> keys;
    vector<string> values;
    void setStartingTransacionId();
};

#endif	/* CONFIGURATIONMANAGER_H */

