#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "commands.h"
#include "task.h"

int welcome();
int updateList(std::vector<Task> tasks);

int main()
{
    std::system("clear");
    // Outputs initial welcome msg
    welcome();

    // Initialises empty vector of tasks
    std::vector<Task> tasks;

    while (true)
    {
        std::cout << "\ndoin\'> ";

        // Get users command
        std::string command{};
        std::getline(std::cin, command);

        // Call the command
        if (command == "exit")
            break;
        else if (command == "add")
        {
            Commands::add(tasks);
        }
        else if (command == "done")
        {
            Commands::done(tasks);
        }
        else if (command == "delete")
        {
            break;
        }
        else if ( command == "help")
        {
            break;
        }
        else
        {
            std::cout << "Command " << command << " is unknown\n";
            continue;
        }
        
        //welcome();
        //std::cout << "Update about to be called\n";
        updateList(tasks);
    }
    
    return 0;
}

int welcome()
{
    //std::system("clear");
    {
        // Writing to the "whatsdoing.txt" file
        std::ofstream outf { "whatsdoing.txt"};
        if (!outf)
            {
                std::cout << "Something went wrong \n";
                return 1;
            }    
        
        std::string welcome {
            "=============================\n"
            "~~~ Welcome to whatsdoin' ~~~\n"
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



int updateList(std::vector<Task> tasks)
{   
    //std::cout << "update called\n";
    //std::cout << "Tasks has size " << tasks.size() << '\n';
    //for (std::size_t i{}; i < tasks.size(); ++i)
    //{
    //    std::cout << tasks[i].id << tasks[i].task << '\n';
    //}
    // Update and write to terminal
        //std::system("clear");            // Wipe the "old" note
        //welcome();                       // Write welcome msg for "new" note

        // Write each task to "new" note
        // Append tasks to the list
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
        {
            std::ofstream outf { "whatsdoing.txt", std::ios::app };
            if (!outf){std::cout << "Something went wrong \n"; return 1;}

            for (std::size_t i{}; i < tasks.size(); ++i)
            {
                // Check if the task has been completed
                if (tasks[i].done)
                {
                    outf << '[' << "\033[32mX\033[0m" << ']' << "  " << tasks[i].task << '\n';
                }
                else
                {
                    outf << '[' << tasks[i].id << ']' << "  " << tasks[i].task << '\n';
                }
            }
        }
        // Read the updated .txt file
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