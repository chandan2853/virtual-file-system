#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "virtualFileSystem.h"

class ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>)=0;
};

#endif