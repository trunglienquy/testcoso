#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *head;
    Node *rear;
};

typedef struct Node *node;

typedef struct Queue *queue;

void init(queue &q){
    q -> head = NULL;
    q -> rear = NULL;
}

node makeNode(int x){
    node tmp = new Node;
    tmp -> data = x;
    tmp -> next = NULL;
    return tmp;
}

// FUNCTION CHECK QUEUE

bool IsEmpty(queue q){
    if (q -> head == NULL)
    {
        return true;
    }
    return false;
}

bool enqueue(queue &q, int x){
    node p = makeNode(x);
    if (p == NULL)
    {
        return false;
    }
    if (IsEmpty(q) == true)
    {
        q -> head = q -> rear = p;
    }
    else
    {
        q -> rear -> next = p;
        q -> rear = p;
    }
    return true;
}

bool dequeue(queue &q, int &x){
    if (IsEmpty(q) == true)
    {
        return false;
    }
    else
    {
        node p = q -> head;
        x = p -> data;
        q -> head = q -> head -> next;
        delete p;
    }
    return true;
}

void PrintQueue(queue q){
    while (IsEmpty(q) == false)
    {
        int x;
        dequeue(q,x);
        cout << x << " ";
    }
    cout << endl;
    if (IsEmpty(q) == true)
    {
        cout << "Queue is Empty!!!" << endl;
    }
}

int main(){
    int lc;
    queue q;
    init(q);
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Display" << endl;
        cout << "Enter your choose: ";
        cin >> lc;
        switch (lc)
        {
        case 1:
            int x;
            cout << "Enter the value: ";
            cin >> x;
            enqueue(q,x);
            break;
        case 2:
            PrintQueue(q);
            break;
        default:
            break;
        }
    } while (lc != 3);
    return 0;
}