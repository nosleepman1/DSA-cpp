#include <iostream>
#include "liste.hpp"


int main(int argc, char const *argv[])
{
    
    liste<int> li;

    li.push_front(5);
    li.push_front(10);
    li.push_front(15);
    li.push_front(20);
    li.push_front(25);
    li.push_back(100);
    li.push_back(200);
    li.push_back(300);

    li.showList();

    std::cout << "\n\nAfifchage apres supression au debut (25-20)" << std::endl;
    li.pop_front();
    li.pop_front();
    li.showList();

    std::cout << "\n\nAfifchage apres supression a la fin (200-300)" << std::endl;
    li.pop_back();
    li.pop_back();
    li.showList();

    std::cout << "\n--------------------------------------------------------------------------------\ninsertion a une position (3)" << std::endl;
    li.insertAt(888, 1);
    li.showList();


    li.showReversedList();

    return 0;
}
