#ifndef COM_H
#define COM_H

#include <iostream>
#include <functional>
typedef void(*funct)(void);
struct option 
{
    std::string desc; 
    std::function<void()> proc;

    bool operator== (const option&a) const
    {
        // Debug: All options are different
        return false;
    }

    bool operator!= (const option&a) const
    {
        // Debug: All options are different
        return true ;
    }
};
typedef struct option option;

#endif