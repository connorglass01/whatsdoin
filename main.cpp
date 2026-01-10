#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "commands.h"
#include "task.h"

int welcome();

int main()
{
    // Outputs initial welcome msg
    welcome();

    // Initialises empty vector of tasks
    std::vector<Task> tasks;

    while (true)
    {
        std::cout << "\ndoin\'> ";

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
    std::system("clear");
    {
        // Writing to the "whatsdoing.txt" file
        std::ofstream outf { "whatsdoing.txt"};
        if (!outf)
            {
                std::cout << "Something went wrong \n";
                return 1;
            }    
        
        std::string welcome {
            "\n"
            "=============================\n"
            "~~~ Welcome to whatsdoing ~~~\n"
            "=============================\n"
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
