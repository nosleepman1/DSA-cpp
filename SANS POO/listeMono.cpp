#include "listeMono.hpp"
#include <iostream>

bool is_Empty(listeMono *li) {
    return li->Front == nullptr;
}

int Length(listeMono *li){
    int length = 0;
    if (is_Empty(li)) return length;

    Node *temp = li->Front;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}


void push_front(listeMono *&li, int value) {
    
    Node *newNode = new Node(value);

    if (is_Empty(li)) {
        li->Front = newNode;
        li->Rear = newNode;
        return;
    }

    newNode->next = li->Front;
    li->Front = newNode;
}


void push_back(listeMono *&li, int value) {
    
    Node *newNode = new Node(value);

    if (is_Empty(li)) {
        li->Front = newNode;
        li->Rear = newNode;
        return;
    }

    li->Rear->next = newNode;
    li->Rear = newNode;
}


void pop_front(listeMono *&li) {

    if (is_Empty(li)) return;

    if (li->Front == li->Rear) {
        li->Front = nullptr;
        li->Rear = nullptr;
        return;
    }

    Node *toDelete = li->Front;
    li->Front = li->Front->next;
    delete toDelete;
}


void pop_back(listeMono *&li) {

    if (is_Empty(li)) return;

    if (li->Front == li->Rear) {
        li->Front = nullptr;
        li->Rear = nullptr;
        return;
    }

    Node *temp = li->Front;
    
    while (temp->next != li->Rear) {
        temp = temp->next;
    }
    
    delete li->Rear;
    temp->next = nullptr;
    li->Rear = temp; 
}


void push_At(listeMono *&li, int value, int pos) {

    if(pos < 1 || pos > Length(li) + 1) return;

    if(pos == 1) {
        push_front(li, value);
        return;
    }
    if (pos == Length(li) + 1 )
    {
        push_back(li, value);
        return;
    }
   
    Node *temp = li->Front;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}


void pop_At(listeMono *&li, int pos) {

    if(pos < 1 || pos > Length(li) ) return;

    if(pos == 1) {
        pop_front(li);
        return;
    }
    if (pos == Length(li) ) {
        pop_back(li);
        return;
    }

    Node *temp = li->Front;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}


void showList(listeMono *li) {

    Node *temp = li->Front;

    while (temp != nullptr) {
        
        std::cout << temp->value << " -> ";
        temp = temp->next;
    }
    std::cout << " null" << std::endl;
    
}