#include "piles.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    
    piles<int> li;
    
    int val = 100;

    for (size_t i = 0; i < 7; i++)
    {
        li.enqueu(val);
        val +=100;
    }
    

    li.showQueue();
    return 0;
}
