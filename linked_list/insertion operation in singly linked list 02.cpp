// Inserting a node after a given node

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
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

void insert_node(Node *node, int item)  /* Inserting a node after a given node */
{
    Node *new_node = create_node(item, node->next);

    node->next = new_node;

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

    head = prepend(head, 10);
    print_linked_list(head);

    //Inserting a node after head node
    insert_node(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    /*Inserting a node after last node and for this situation we
      need to first find out the last node.
    */

    Node *node = head;

    while(node->next != NULL) node = node->next;

    insert_node(node, 40);
    print_linked_list(head);

    return 0;
}
