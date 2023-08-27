#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class TouchCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class RMCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class MkdirCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class CDCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class LSCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class RmdirCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem>);
};

class HelpCommand : public ICommand
{
    public:
        virtual bool executeCommand(std::vector<std::string>, std::shared_ptr<VirtualFileSystem> filesystem);
};
int isDataAlreadyExist(std::string,std::string,std::shared_ptr<VirtualFileSystem>);

#endif