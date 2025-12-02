#include <iostream>
#include "liste.hpp"


int main()
{
    
    liste <int> li;

    // test des fonctions
    std::cout << "La longueur de la liste est " << li.length() << "\n\n" << std::endl;

    li.push_front(18);
    li.push_front(14);
    li.push_front(17);
    li.push_front(10);
    li.push_back(222);
    li.push_back(227);
    li.push_back(311);
    li.showList();
    //li.pop_back();
    li.pop_back();
    li.showList();
    return 0;
}
