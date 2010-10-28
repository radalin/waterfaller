/* 
 * File:   ConfigurationManager.h
 * Author: roysimkes
 *
 * Created on October 28, 2010, 12:22 AM
 */

#ifndef CONFIGURATIONMANAGER_H
#define	CONFIGURATIONMANAGER_H

class ConfigurationManager {
public:
    static ConfigurationManager* getInstance();
private:
    ConfigurationManager();
    virtual ~ConfigurationManager();
    static ConfigurationManager* _instance;
};

#endif	/* CONFIGURATIONMANAGER_H */

