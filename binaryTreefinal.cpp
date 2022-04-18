#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

typedef struct Node *node;

node createNode(int x){
    node tmp = new Node;
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

node addTree(node &root, int x){
    if (root == NULL)
    {
        return root = createNode(x);
    }
    
    if (root->data < x)
    {
       addTree(root->right, x);
    }
    else
    {
        addTree(root->left, x);
    }
    return root;
}

node find(node root, int k){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < k)
    {
        return find(root->right, k);
    }
    else if (root->data > k)
    {
        return find(root->left, k);
    }
    else
    {
        return root;
    }
}

node minvalue(node root){
    node p = root;
    while (p != NULL && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}

node remove(node root, int x){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > x)
    {
        root->left = remove(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = remove(root->right, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            node tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            node tmp = root->left;
            free(root);
            return tmp;
        }
        else
        {
            node tmp = minvalue(root->right);
            root->data = tmp->data;
            root->right = remove(root->right, tmp->data);
        }
    }
    return root;
}

void NLR(node root){
    if (root != NULL)
    {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
    
}

int main(){
    node root = NULL;
    root = addTree(root,3);
    root = addTree(root,2);
    root = addTree(root,0);
    root = addTree(root,4);
    root = addTree(root,5);
    root = addTree(root,6);
    NLR(root);
    cout << endl;
    cout << find(root,30);
    cout <<endl;
    cout << find(root,2);
    cout <<endl;

    cout << find(root,3);
    cout <<endl;

    cout << find(root,300);
    cout <<endl;
    remove(root,3);
    NLR(root);


    return 0;
}