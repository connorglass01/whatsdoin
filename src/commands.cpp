#include "commands.h"
#include "task.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace Commands
{
    // Creates ID for each task
    int generateID()
    {
        static int s_itemID {0};
        return s_itemID++; //makes copy of s_itemID, increments real s_itemID and returns copy
    }

    // Creating, writing and reading a new task
    int add(std::vector<Task>& tasks)
    {
        std::cout << "Task: ";
        Task newTask{};
        newTask.id = generateID();
        std::getline(std::cin, newTask.task);
        tasks.push_back(newTask);

        return 0;
    }

    int done(std::vector<Task>& tasks)
    {
        // If user types done with no tasks to remove
        if (tasks.empty())
        {
            return 0;
        }

        int numTasks { static_cast<int>(tasks.size()) };
        int taskID;

        while(true)
        {
            std::cout << "Task ID [0 - " << numTasks - 1 << "]:\n";

            if ((std::cin >> taskID) && 0<= taskID < numTasks + 1)
            {
                std::cin.ignore(1000, '\n');
                break;
            }
            else
            {
                std::cout << "Invaild ID input. Please try again.\n";
                std::cin.clear();
            }
            
            std::cin.ignore(1000, '\n');
        }
        
        std::size_t ID = static_cast<std::size_t>(taskID);
        
        tasks[ID].done = true; 

        return 0;
    }



    int remove(std::vector<Task>& tasks)
    {
        // If user types done with no tasks to remove
        if (tasks.empty())
        {
            return 0;
        }

        int numTasks { static_cast<int>(tasks.size()) };
        int taskID;

        while(true)
        {
            std::cout << "Task ID [0 - " << numTasks - 1 << "]:\n";

            if ((std::cin >> taskID) && 0<= taskID < numTasks + 1)
            {
                std::cin.ignore(1000, '\n');
                break;
            }
            else
            {
                std::cout << "Invaild ID input. Please try again.\n";
                std::cin.clear();
            }
            
            std::cin.ignore(1000, '\n');
        }
        
        tasks.erase(tasks.begin() + taskID);

        std::size_t newNumTasks { tasks.size() };

        for (std::size_t i{}; i <= newNumTasks; ++i)
        {
            tasks[i].id = static_cast<int>(i);
        } 

        return 0;
    }


    int help()
    {
        {
        std::ofstream outf { "whatsdoing.txt", std::ios::app };
        if (!outf){std::cout << "Something went wrong writing \n"; return 1;}

        std::string helpMsg {
            "\n"
            "\033[1madd\033[0m + |return|    - add a task\n"
            "\033[1mdone\033[0m + |return|   - toggle task completion\n"
            "\033[1mremove\033[0m + |return| - remove a task\n"
            "\033[1mexit\033[0m + |return|   - exit application"
        };
        outf << helpMsg;
        }


        std::ifstream inf { "whatsdoing.txt" };
        if (!inf){std::cout << "something went wrong reading\n"; return 1;}

        std::string strInput;
        while (std::getline(inf, strInput))
        {
            std::cout << strInput << '\n';
        }
        return 0;

    }
}