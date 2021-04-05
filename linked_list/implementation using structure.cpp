/// Implementation of singly linked list data structure

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *create_node(int data, Node* next)
{
    Node *new_node = new Node();

    if(new_node == NULL){
        cout<<"Error! Could not create a new node!\n";
        exit(1);
    }

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

int main()
{
    Node *head = NULL;

    Node *n1 = create_node(10, NULL);

    head = n1;

    cout<<head->data<<endl;

    return 0;
}



