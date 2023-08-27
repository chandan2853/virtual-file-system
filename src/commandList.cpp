#include <iostream>
#include "../inc/commandList.h"
#include "virtualFileSystem.cpp"


bool RMCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    if(command.size()<=1)
    {
        std::cout<<"Invalid argument, rm (file name)"<<std::endl;
        return false;
    }
    bool flag=false;
    for(int i=1;i<command.size();i++)
    {
        int index=isDataAlreadyExist(command[i],"file",filesystem);
        if(index!=-1)
        {
            filesystem->currentDirectory->nextDirectory.erase(filesystem->currentDirectory->nextDirectory.begin()+index);  
            flag=true;
        }
        else
        {
            std::cout<<"rm: file not found"<<std::endl;
        }
    }
    return flag;
}

bool TouchCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    if(command.size()<=1)
    {
        std::cout<<"Invalid argument, touch (file name)"<<std::endl;
        return false;
    }
    bool flag=true;
    for(int i=1;i<command.size();i++)
    {
        int index=isDataAlreadyExist(command[i],"file",filesystem);
        if(index==-1)
        {
            std::shared_ptr<virtualFileSystemComponents> file=std::make_shared<virtualFileSystemComponents>(command[i]);
            file->previousDirectory=filesystem->currentDirectory;
            file->absolutePath=file->previousDirectory->absolutePath+"/"+file->name;
            file->componentType="file";
            filesystem->currentDirectory->nextDirectory.push_back(file);
        }
        else
        {
            std::cout<<command[i]<<" File already exist"<<std::endl;
            flag=false;
        }
    }
    return flag;
}

bool CDCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    if(command.size()==1)
    {
        filesystem->currentDirectory=filesystem->root;
        filesystem->temp=filesystem->root->absolutePath;
        return true;
    }
    if(command.size()!=2)
    {
        std::cout<<"Invalid argument, cd (directory name) / cd for root/ cd .. for previous"<<std::endl;
        return false;
    }
    if(command[1]=="..")
    {
        if(filesystem->temp=="root")
        {
            std::cout<<"No previous directory available"<<std::endl;
            return false;
        }
        filesystem->currentDirectory=filesystem->currentDirectory->previousDirectory;
        filesystem->temp=filesystem->currentDirectory->absolutePath;
        return true;
    }
    bool flag=false;
    for(int i=0; i< filesystem->currentDirectory->nextDirectory.size();i++)
    {
        if(filesystem->currentDirectory->nextDirectory[i]->name==command[1] && filesystem->currentDirectory->nextDirectory[i]->componentType=="directory")
        {
            filesystem->currentDirectory=filesystem->currentDirectory->nextDirectory[i];
            filesystem->temp=filesystem->currentDirectory->absolutePath;
            flag=true;
        }
    }
    if(!flag)
    {
        std::cout<<"No such directory"<<std::endl;
    }
    return flag;
}

bool MkdirCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    if(command.size()<=1)
    {
        std::cout<<"Invalid argument, mkdir (directory name)"<<std::endl;
        return false;
    }
    bool flag=true;
    for(int i=1;i<command.size();i++)
    {
        int index=isDataAlreadyExist(command[i],"directory",filesystem);
        if(index==-1 && command[i]!="." && command[i]!=".." && command[i]!="/")
        {
            std::shared_ptr<virtualFileSystemComponents> dir=std::make_shared<virtualFileSystemComponents>(command[i]);
            dir->previousDirectory=filesystem->currentDirectory;
            dir->absolutePath=dir->previousDirectory->absolutePath+"/"+dir->name;
            dir->componentType="directory";
            filesystem->currentDirectory->nextDirectory.push_back(dir);
        }
        else
        {
            std::cout<<command[i]<<" directory already exist"<<std::endl;
            flag=false;
        }
    }
    return flag;
}

bool RmdirCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    if(command.size()<=1)
    {
        std::cout<<"Invalid argument, rm (file name)"<<std::endl;
        return false;
    }
    bool flag=false;

    for(int i=1;i<command.size();i++)
    {
        int index=isDataAlreadyExist(command[i],"directory",filesystem);
        if(index!=-1)
        {
            filesystem->currentDirectory->nextDirectory.erase(filesystem->currentDirectory->nextDirectory.begin()+index);  
            flag=true;
        }
        else
        {
            std::cout<<command[i]<<" directory not found"<<std::endl;
        }
    }
    return flag;
}

bool LSCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    bool flag=true;
    if(command.size()>1)
    {
        std::cout<<"no argument in ls command"<<std::endl;
        flag=false;
    }
    else if(filesystem->currentDirectory->nextDirectory.size()==0)
    {
        std::cout<<"No file or directory present"<<std::endl;
    }
    else
    {
                              
        for(auto i: filesystem->currentDirectory->nextDirectory)
        {
            std::cout<<i->name<<" ("<<i->componentType<<") "<<std::endl;
        }
    }
    return flag;
}

bool HelpCommand ::executeCommand(std::vector<std::string> command, std::shared_ptr<VirtualFileSystem> filesystem)
{
    bool flag=true;
    if(command.size()>1)
    {
        std::cout<<"no argument in help command"<<std::endl;
        flag=false;
    }
    std::cout<<"rm: remove a file, syntax: rm file"<<std::endl;
    std::cout<<"ls: list "<<std::endl;
    std::cout<<"mkdir: make a directory "<<std::endl;
    std::cout<<"rmdir remove directory "<<std::endl;
    std::cout<<"cd: change directory"<<std::endl;
    std::cout<<"touch: create a file"<<std::endl;
    std::cout<<"help: list all commands"<<std::endl;
    return flag;
}

int isDataAlreadyExist(std::string name,std::string fileType,std::shared_ptr<VirtualFileSystem> filesystem)
{
    int index=-1;
    for(int i=0; i< filesystem->currentDirectory->nextDirectory.size();i++)
    {
        if(filesystem->currentDirectory->nextDirectory[i]->name==name && filesystem->currentDirectory->nextDirectory[i]->componentType==fileType)
        {
            index=i;
        }
    }
    return index;
}