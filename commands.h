#ifndef COMMANDS_H
#define COMMANDS_H

#include "task.h"

namespace Commands
{
    int add(std::vector<Task>& tasks);
    int done(std::vector<Task>& tasks);
    int remove(std::vector<Task>& tasks);
    int help();
}


#endif 