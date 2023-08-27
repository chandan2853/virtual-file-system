#include <iostream>
#include <string>
#include <sstream>
#include "../inc/iCommand.h"
#include "../src/commandParser.cpp"
#include "../src/commandList.cpp"
#include "../inc/virtualFileSystemComponents.h"
int main()
{
    std::string inputCommand;
    std::shared_ptr<VirtualFileSystem> filesystem = std::make_shared<VirtualFileSystem>();
    while(true)
    {
        
        std::cout<<"<VFS> "<<(filesystem->temp)<<" $ ";

        getline(std::cin,inputCommand);
        
        if(inputCommand=="quit" || inputCommand=="q")
        {
            break;
        }
        else if(inputCommand=="")
        {
            std::cout<<"Empty"<<std::endl;
            continue;
        }
        else
        {
            CommandParser parse;
            parse.commandParse(inputCommand,filesystem);
        }
    }
    std::cout<<"End of Virtual File System"<<std::endl;    
    return 0;
}