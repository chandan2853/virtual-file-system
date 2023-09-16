#ifndef VIRTUALFILESYSTEM_H
#define VIRTUALFILESYSTEM_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "virtualFileSystemComponents.h"

class VirtualFileSystem
{
    public:
        std::shared_ptr<virtualFileSystemComponents> root;
        std::shared_ptr<virtualFileSystemComponents> currentDirectory;
        std::string temp;
        VirtualFileSystem();
        ~VirtualFileSystem(){}
};

#endif