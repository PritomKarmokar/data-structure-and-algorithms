/* counting total number of nodes presented in the singly linked list */

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next) /* Creating a node */
{
    Node *new_node = new Node();

    if(new_node == NULL){
        cout<<"Error! Could not create a new node!!\n";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item)  /* inserting a node at the head */
{
    Node *new_node = create_node(item, head);

    return new_node;
}

Node *append(Node *head, int item)  /* inserting node at the last */
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

void insert_node(Node *node, int item)    /* inserting node after a given node */
{
    Node *new_node = create_node(item, node->next);

    node->next = new_node;
}

int count_node(Node *head)  /* counting total nodes */
{
    int total = 0;

    Node *current_node = head;

    while(current_node != NULL){
        total += 1;
        current_node = current_node->next;
    }

    return total;
}

void print_linked_list(Node *head)    /* printing elements of the linked list */
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
    int total ;

    total = count_node(head);
    cout<<"There are "<<total<<" nodes presented in the linked list\n\n";

    head = prepend(head, 10);
    insert_node(head, 20);
    head = prepend(head, 30);

    total = count_node(head);
    cout<<"There are "<<total<<" nodes presented in the linked list\n\n";

    print_linked_list(head); // Printing elements of the linked list

    return 0;
}
