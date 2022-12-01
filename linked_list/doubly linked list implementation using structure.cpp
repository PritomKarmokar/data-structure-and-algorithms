// Whole code need to modify in a more structural way.

#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *prev;
};

// Function for creating a node.
Node *create_node(int data, Node *next, Node *prev)
{
    Node *new_node = new Node();

    if(new_node == NULL)
    {
        cout << "Error! Could not create a new node" << endl;
        exit(1);
    }

    new_node->data = data;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

// Function for adding node at the start.
Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head, NULL);
    new_node->next->prev = new_node;
    return new_node;
}


// Function for adding node at the end.
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL, NULL);

    if(head == NULL){
        return new_node;
    }

    Node *cur_node = head;

    while(cur_node->next != NULL){
        cur_node = cur_node->next;
    }

    cur_node->next = new_node;
    new_node->prev = cur_node;

    return head;
}

// Function for removing node.
Node *remove_node(Node *head, Node *node)
{
    if(node == head){
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }

    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = node->prev;
    next_node->prev = previous_node;

    free(node);

    return head;
}

// Function for inserting a node after a given node.
void insert_node(Node *node , int data)
{
    Node *new_node = create_node(data, node->next, node); // (data, next_node, prev_node)

    node->next->prev = new_node;

    node->next = new_node;
}

// Function for printing elements of the linked list.
void printList(Node *head)
{
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return;
    }
    
    cout << "Elements of the Linked List are : ";
    Node* cur = head;

    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}


int main()
{
    Node *n1 = create_node(10, NULL, NULL);

    cout << n1->data << endl;

    Node *head = n1;

    printList(head);

    head = prepend(head, 20);

    printList(head);

    n1 = head->next;

    cout << n1->prev->data << endl;

    head = append(head, 30);

    printList(head);

    // cout << n1->data << endl;

    insert_node(n1, 15);

    printList(head);
    
    return 0;
}