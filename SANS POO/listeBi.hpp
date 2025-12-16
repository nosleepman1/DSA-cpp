typedef struct Node
{
    int value;
    Node *next;
    Node *prev;
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
}Node;

typedef struct listeBi {
    Node *Front;
    Node *Rear;
    listeBi(): Front(nullptr), Rear(nullptr) {}
} listeBi;

void push_front(listeBi *&li, int value);
void push_back(listeBi *&li, int value);

void pop_front(listeBi *&li);
void pop_back(listeBi *&li);

void push_At(listeBi *&li, int value, int pos);
void pop_At(listeBi *&li, int pos);

void showList(listeBi *li);
void showReversedList(listeBi *li);


bool is_Empty(listeBi *li);
int Length(listeBi *li);


