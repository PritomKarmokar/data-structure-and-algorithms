/* Deleting a node where the data of the node is given */

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

Node *remove_node(Node *head, int item)
{
    Node *node = search_node(head, item);

    if(node == NULL){
        cout<<item<<" is not presented in the linked list.So, cannot remove the node\n\n";
    }
    else if(node == head){
        head = node->next;
        free(node);
    }
    else{
        Node *current_node = head;

        while(current_node->next != node){
            current_node = current_node->next;
        }

        current_node->next = node->next;
        free(node);
    }

    return head;
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

    insert_node(head, 20);
    print_linked_list(head);

    head = prepend(head, 30);
    print_linked_list(head);

    int value = n1->data;
    head = remove_node(head, value);
    print_linked_list(head);

    value = 40;
    head = remove_node(head, value);
    print_linked_list(head);

    value = head->data;
    head = remove_node(head, value);
    print_linked_list(head);

    value = head->data;
    head = remove_node(head, value);
    print_linked_list(head);

    return 0;
}
