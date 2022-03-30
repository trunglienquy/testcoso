#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef struct Node* node;

node top = NULL;

void push(int x)
{
    node tmp = new Node();
    tmp -> data = x;
    tmp -> next = top;
    top = tmp;
}

void pop() 
{
    if (top == NULL)
    {
        cout << "Stack Empty";
    }
    else
    {
        node tmp = top;
        top = top -> next;
        delete(tmp);
    }
}

void deleteStack(){
    while (top != NULL)
    {
        pop();
    }
    
}

void displayTop()
{
    if (top == NULL)
    {
        cout << "Stack Empty";
    }
    else
    {
        cout << "Value is top: " << top -> data;
    }
}

void chuyen_co_so(int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;
        push(x);
        hethapphan /= cosocandoi;
    }
    
}

void display()
{
    int x = 0;
    while (top != NULL)
    {
        if (x < 10)
        {
            cout << top -> data << " ";

        }
        else{
            if (top -> data > 10)
            {
                cout << char(top -> data + 55) << " ";
            }else{
                cout << top -> data;
            }
        }
        
        top = top -> next;
    }
    cout << endl;
}

int main(){
    int lc;
    node head = NULL;
    int hethapphan, cosocandoi;
    do
    {
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Print" << endl;
        cout << "5.Chuyen doi co so" << endl;
        cout << "Enter your choose: " << endl;
        cin >> lc;
        switch (lc)
        {
        case 1:
            int x;
            cout << "Enter Value: ";
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayTop();
            break;
        case 4:
            display();
            break;
        case 5:
            deleteStack();
            cout << "Nhap gia tri thap phan can doi: " << endl;
            cin >> hethapphan;
            cout << "Nhap co so can chuyen (2,8,16): " << endl;
            cin >> cosocandoi;
            chuyen_co_so(cosocandoi, hethapphan);
        default:
            break;
        }
    } while (lc != 6);
    
    return 0;
}