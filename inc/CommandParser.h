#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <vector>
#include <string>
#include "commandList.h"

class CommandParser
{
    public:
        ICommand *icommand;
        bool commandParse(std::string inputCommand, std::shared_ptr<VirtualFileSystem> filesystem);

};

#endif
