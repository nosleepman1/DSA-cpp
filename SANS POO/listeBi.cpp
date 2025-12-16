#include "listeBi.hpp"
#include <iostream>


bool is_Empty(listeBi *li) {
    return li->Front == nullptr;
}

int Length(listeBi *li){
    int length = 0;
    if (is_Empty(li)) return length;

    Node *temp = li->Front;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}


void push_front(listeBi *&li, int value) {

    Node *newNode = new Node(value);

    if (is_Empty(li)) {
        li->Front  = newNode;
        li->Rear = newNode;
        return;
    }

    newNode->next = li->Front;
    li->Front->prev = newNode;
    li->Front = newNode;
    
}

void push_back(listeBi *&li, int value) {

    Node *newNode = new Node(value);

    if (is_Empty(li)) {
        li->Front  = newNode;
        li->Rear = newNode;
        return;
    }

    li->Rear->next = newNode;
    newNode->prev = li->Rear;
    li->Rear = newNode;
}

void pop_front(listeBi *&li) {

    if(is_Empty(li)) return;

    if (li->Front == li->Rear) {
        li->Front = nullptr;
        li->Rear = nullptr;
    }
    
    Node *toDelete = li->Front;
    li->Front = toDelete->next;
    delete toDelete;
}

void pop_back(listeBi *&li) {
    
    if(is_Empty(li)) return;

    if (li->Front == li->Rear) {
        li->Front = nullptr;
        li->Rear = nullptr;
    }

    Node *toDelete = li->Rear->prev;
    li->Rear = toDelete;
    li->Rear->next = nullptr;
}

void push_At(listeBi *&li, int value, int pos) {

    if(pos < 1 || pos > Length(li) + 1) return;
    if (pos == 1){ push_front(li, value); return; }
    if (pos == Length(li)+1){ push_back(li, value); return; }

    Node *temp = li->Front;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    Node *newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}


void pop_At(listeBi *&li, int pos) {

    if(pos < 1 || pos > Length(li)) return;
    if (pos == 1) { 
        pop_front(li); 
        return; 
    }

    if (pos == Length(li)) { 
        pop_back(li); 
        return; 
    }

    Node *temp = li->Front;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    Node *toDelete = temp->next;

    temp->next = toDelete->next;
    toDelete->next->prev = temp;

    delete toDelete;
}

void showList(listeBi *li) {

    if (is_Empty(li)) {
        std::cout << "Liste vide" << std::endl;
        return;
    }

    Node *temp = li->Front;

    while (temp != nullptr)
    {
        std::cout << temp->value << " -> ";
        temp = temp->next;
    }
    std::cout <<  " null " << std::endl;
    
}

void showReversedList(listeBi *li) {

    if (is_Empty(li)) {
        std::cout << "Liste vide" << std::endl;
        return;
    }

    Node *temp = li->Rear;

    while (temp != nullptr)
    {
        std::cout << temp->value << " <- ";
        temp = temp->prev;
    }
    std::cout <<  " null " << std::endl;
    
    
}
