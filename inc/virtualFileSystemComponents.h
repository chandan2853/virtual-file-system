#ifndef VIRTUALFILESYSTEMCOMPONENTS_H
#define VIRTUALFILESYSTEMCOMPONENTS_H

#include <iostream>
#include <vector>
#include <memory>
#include <list>

class virtualFileSystemComponents
{
    public:
        std::string name;
        std::string absolutePath;
        std::string componentType;
        std::shared_ptr<virtualFileSystemComponents> previousDirectory;
        std::vector<std::shared_ptr<virtualFileSystemComponents>> nextDirectory;
        virtualFileSystemComponents(std::string name):name(name){}    
};


#endif