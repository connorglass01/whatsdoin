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
}