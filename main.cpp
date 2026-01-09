#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "commands.h"

int welcome();

int main()
{
    welcome();

    while (true)
    {
        std::cout << "doin\'> ";

        std::string command{};
        std::getline(std::cin, command);

        if (command == "exit")
            break;
        else if (command == "add")
        {
            Commands::add();
        }
        else
            std::cout << "Command " << command << " is unknown\n";
    }

    //std::system("clear");

    return 0;
}

int welcome()
{
    {
        // Writing to the "whatsdoing.txt" file
        std::ofstream outf { "whatsdoing.txt"};
        if (!outf)
            {
                std::cout << "Something went wrong \n";
                return 1;
            }    
        
        std::string welcome {
            "~~~ Welcome to whatsdoing ~~~\n"
        };
        outf << welcome;
    }   // outf goes out of scope (equiv. to outf.close())

    // Reading the "whatsdoing.txt" file
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
