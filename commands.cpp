#include "commands.h"
#include "task.h"

#include <iostream>
#include <string>
#include <fstream>

namespace Commands
{
    // Creates ID for each task
    int generateID()
    {
        static int s_itemID {0};
        return s_itemID++; //makes copy of s_itemID, increments real s_itemID and returns copy
    }

    // Creating, writing and reading a new task
    int add()
    {
        std::cout << "Task: ";
        Task newTask{};
        newTask.id = generateID();
        std::getline(std::cin, newTask.task);

        {
            std::ofstream outf { "whatsdoing.txt", std::ios::app };
            if (!outf)
            {
                std::cout << "Something went wrong \n";
                return 1;
            }

            outf << newTask.id << "  " << newTask.task << '\n';
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