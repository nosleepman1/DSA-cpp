typedef struct Node
{
    int value;
    Node *next;
    Node(int val) : value(val), next(nullptr) {}
}Node;

typedef struct listeMono {
    Node *Front;
    Node *Rear;
    listeMono(): Front(nullptr), Rear(nullptr) {}
} listeMono;

void push_front(listeMono *&li, int value);
void push_back(listeMono *&li, int value);

void pop_front(listeMono *&li);
void pop_back(listeMono *&li);

void push_At(listeMono *&li, int value, int pos);
void pop_At(listeMono *&li, int pos);

void showList(listeMono *li);


bool is_Empty(listeMono *li);
int Length(listeMono *li);


