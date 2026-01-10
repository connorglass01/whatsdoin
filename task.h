#ifndef TASK_H
#define TASK_H

#include <string>


struct Task
{
    int id{};
    std::string task{};
    bool done { false };
};

#endif 