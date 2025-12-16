#include <iostream>
//#include "listeMono.hpp"
#include "listeBi.hpp"

int main()
{
    listeBi *liste;

  


    push_front(liste, 10);
    push_front(liste, 20);
    push_front(liste, 30);
    push_front(liste, 40);

    push_back(liste, 500);
    push_back(liste, 600);
    push_back(liste, 700);
    push_back(liste, 800);

    showList(liste);
    std::cout << "-----------------------------------" << std::endl;

    push_At(liste, 555, 3);
    showList(liste);
    std::cout << "-----------------------------------" << std::endl;

    pop_At(liste, 4);
    showList(liste);
    std::cout << "-----------------------------------" << std::endl;


    return 0;
}
