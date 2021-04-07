/* Searching a node in the linked list where the data of the node is given*/

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

Node *search_node(Node *head, int item)    /* Searching any node where the data of the node is given */
{
   Node *current_node = head;

   while(current_node != NULL){
        if(current_node->data == item){
            break;
        }
        current_node = current_node->next;
   }

   return current_node;
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
    Node *n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    insert_node(head, 15);
    print_linked_list(head);

    n1 = head->next;
    insert_node(n1, 20);
    print_linked_list(head);

    head = append(head, 25);
    print_linked_list(head);

    head = prepend(head, 5);
    print_linked_list(head);

    Node *node = search_node(head, 10);

    if(node == NULL){
         cout<<"Node is not presented in the linked list\n\n";
    }
    else{
        cout<<node->data<<" is presented in the linked list\n\n";
    }

    node = search_node(head, 30);

    if(node == NULL){
         cout<<"Node is not presented in the linked list\n\n";
    }
    else{
        cout<<node->data<<" is presented in the linked list\n\n";
    }

    return 0;
}
