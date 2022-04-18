#include <iostream>
using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

void enqueue(){
    int item;
    if (rear == n -1)
    {
        cout << "Overflow!!!" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        cout << "Enter value Queue: ";
        cin >> item;
        rear ++;
        queue[rear] = item;
    }
}

void dequeue(){
    if (front == -1 && rear == -1)
    {
        cout << "Underflow!!!" << endl;
    }
    else if (front == rear)
    {
        front = rear = - 1;
    }
    else
    {
        front ++;
    }
}

void dispaly(){
    int i = front;
    if (front == -1)
    {
        cout << "Queue is empty!!!" << endl;
    }
    else
    {
        while (i <= rear)
        {
            cout << queue[i] << " ";
            i++;
        }
        cout << endl;
    }
    
}

int main(){
    int lc;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choose: ";
        cin >> lc;
        switch (lc)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            dispaly();
            break;
        default:
            break;
        }
    } while (lc != 4);
    
    return 0;
}