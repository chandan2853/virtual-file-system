#include<sstream>
#include "../inc/virtualFileSystem.h"
#include "../inc/CommandParser.h"

bool CommandParser::commandParse(std::string inputCommand, std::shared_ptr<VirtualFileSystem> filesystem)
{
    bool flag=true;
    std::vector<std::string> command;
    std::string tempStr;
    std::stringstream ss(inputCommand);
    while(getline(ss,tempStr,' '))
    {
        command.push_back(tempStr);
    }
    if(command[0]=="cd")
    {
        icommand=new CDCommand();
        flag=icommand->executeCommand(command, filesystem);
    }
    else if(command[0]=="rm")
    {
        icommand=new RMCommand();
        flag=icommand->executeCommand(command, filesystem);
    }
    else if(command[0]=="touch")
    {
        icommand=new TouchCommand();
        flag=icommand->executeCommand(command, filesystem);
    }
    else if(command[0]=="mkdir")
    {
        icommand=new MkdirCommand();
        flag=icommand->executeCommand(command, filesystem);
    }
    else if(command[0]=="ls")
    {
        icommand=new LSCommand();
        flag=icommand->executeCommand(command,filesystem);
    }
    else if(command[0]=="rmdir")
    {
        icommand=new RmdirCommand();
        flag=icommand->executeCommand(command, filesystem);
    }
    else if(command[0]=="help")
    {
        icommand=new HelpCommand();
        flag=icommand->executeCommand(command,filesystem);
    }
    else
    {
        flag=false;
        std::cout<<"Invalid Command!"<<std::endl;
    }
    if(icommand)
    {
        delete icommand;
    }
    return flag;
}