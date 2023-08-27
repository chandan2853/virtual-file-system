#include <iostream>
#include "../inc/virtualFileSystem.h"

VirtualFileSystem::VirtualFileSystem()
{
    root = std::make_shared<virtualFileSystemComponents>("root");
    root->previousDirectory=0;
    currentDirectory=root;
    root->absolutePath=root->name;
    temp=root->absolutePath;
}