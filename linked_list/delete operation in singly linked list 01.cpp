// Deleting a node at head , at last or between the head and last node

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

void insert_node(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);

    node->next = new_node;

}

Node *remove_node(Node *head, Node *node)
{
    if(head == node){
        head = head->next;
        free(node);
        return head;
    }

    Node *current_node = head;

    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }

    if(current_node == NULL){
        return head;
    }

    current_node->next = node->next;
    free(node);

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

    Node *n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);

    insert_node(n1,40);
    print_linked_list(head);

    /* Performing delete operation */

    head = remove_node(head, n1);
    print_linked_list(head);

    /* Delete last node of the linked list */

    Node *node = head;
    while(node->next != NULL) node = node->next;

    head = remove_node(head, node);
    print_linked_list(head);

    /* delete the next node after head*/

    n1 = head->next;
    head = remove_node(head, n1);
    print_linked_list(head);

    head = remove_node(head, head);
    print_linked_list(head);

    return 0;
}
