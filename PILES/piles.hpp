#include <iostream>
using namespace std;


template <typename T>
class piles
{
private:
    typedef struct node {
        T value;
        node *next;
        node(T val) : value(val), next(nullptr) {}
    }node;

    node *top;
public:
    piles() :top(nullptr) {};
    ~piles() {};

    bool isEmpty(){
        return this->top == nullptr;
    }

    int length(){
        if (isEmpty()) return 0;

        node *temp = this->top;
        int longueur = 0;
        while (temp != nullptr)
        {
            longueur++;
            temp = temp->next;
        }
        return longueur;
    }

    void enqueu(T val) {
        node* newNode = new node(val);

        newNode->next = this->top;
        this->top = newNode;
    }

    void dequeue() {
       if (isEmpty()) {
         return;
       } else if (top->next == nullptr) {
            top = nullptr;
            return;
        } 
        node *todelete = this->top;

        this->top = this->top->next;
        delete todelete;
    }

    void showQueue() {
        
        node *temp = this->top;

        while (temp != nullptr)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << " NULL";
    }
};




