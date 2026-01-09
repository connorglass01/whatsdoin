#include "commands.h"

#include <iostream>
#include <string>
#include <fstream>

namespace Commands
{
    int add()
    {
        std::cout << "Task: ";
        std::string task;
        std::getline(std::cin, task);

        {
            std::ofstream outf { "whatsdoing.txt", std::ios::app };
            if (!outf)
            {
                std::cout << "Something went wrong \n";
                return 1;
            }    
            outf << task;
        }

        std::system("clear");

        // Reading the "whatsdoing.txt" file with the new task
        std::ifstream inf { "whatsdoing.txt" };
        if (!inf)
        {
            std::cout << "something went wrong reading\n";
            return 1;
        }

        std::string strInput;
        while (std::getline(inf, strInput))
        {
            std::cout << strInput << '\n';
        }
        
        return 0;
    }
}