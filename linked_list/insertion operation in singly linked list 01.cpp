/*
Inserting a node in the linked list.

Here we are considering two cases :
    01.Inserting at head
    02.Inserting at last node of the linked list.
*/

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = new Node(); ///Here for allocating memory malloc, calloc and realloc can also be used

    if(new_node == NULL){
        cout<<"Error! Could not create a new node!!\n";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);

    return new_node;
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL){
        return new_node;
    }

    Node *current_node = head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

void print_linked_list(Node *head)
{
    if(head == NULL){
        cout<<"Linked list is empty!";
    }
    else{
        cout<<"Linked list is : ";

        Node *current_node = head;

        while(current_node != NULL){
            cout<<current_node->data<<" ";
            current_node = current_node->next;
        }
    }
    cout<<"\n\n";
}

int main()
{
    Node *head = NULL;
    print_linked_list(head);

    Node *n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    return 0;
}
