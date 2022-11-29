// Pura program ta aro modify kora lagbe.
// https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // This function can pass next node in the parameter.
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class linkedList
{
    Node *head;

public:
    // Constructor
    linkedList()
    {
        head = NULL;
    }

    void insertNode(int);

    // Inserting a node at the head.
    void prepend(int data);

    // Inserting a node at the end.
    void append(int data);

    // Deleting a node
    void remove_node(int data);

    void printList();

    bool search(int);

    int count();
};

// Utility function to insert a node into the linked list.
void linkedList :: insertNode(int data)
{
    Node *newNode = new Node(data);

    // Assign to head
    if(head == NULL){
        head = newNode;
        return ;
    }

    // If head node is not NULL add the node at the end 
    // Traverse till end of the list
    Node *temp = head;
    while( temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

// Utility function to print the list.
void linkedList :: printList()
{
    cout << "Elements of the linked list are : ";

    Node *temp = head;

    if(head == NULL){
        cout << "List is empty!!" << endl;
        return;
    }

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Utility function to add new node at the head position.
void linkedList :: prepend(int data)
{
    Node *newNode = new Node(data, head);
    head = newNode;

    return ;
}

// Utility function to add new node at the end position.
void linkedList :: append(int data)
{
    Node *newNode = new Node(data);
    Node *cur = head;

    while(cur->next != NULL){
        cur = cur->next;
    }

    cur->next = newNode;
}

// Utility function to remove a node from the linked list
// Program ta hoise but aro modify korte hobe.
void linkedList :: remove_node(int data)
{
    // If the given node is the head node.
    if(head->data == data){
        Node *temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node *cur_node = head;
    Node *temp;
    while(cur_node != NULL){
        if(cur_node->next->data == data){
            temp = cur_node->next;
            break;
        }
        cur_node = cur_node->next;
    }

    // If the node is not presented in the linked list.
    if(cur_node == NULL){
        cout << "The node is not presented in the linked list." << endl;
        return;
    }

    // We find the node and then perform operation. 'Need to modify text here.'
    Node *node = cur_node->next; // Ei node tai delete korte hobe

    cur_node->next = temp->next;

    delete node;

}

// Utility function to searh a node with value equals to item in the list.
bool linkedList :: search(int item)
{
    Node *cur = head;

    while(cur != NULL){
        if(cur->data == item){
            return true;
        }
        cur = cur->next;
    }

    return false;
}

// Utility function to return total num of nodes presented in the linked list.
int linkedList :: count()
{
    Node *cur = head;
    int total = 0;

    while(cur != NULL){
        total += 1;
        cur = cur->next;
    }

    return total;
}

int main()
{
    linkedList list;

    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);

    list.printList();

    list.prepend(4);
    list.printList();

    list.append(10);
    list.printList();
    
    int val = 3;
    bool found = list.search(val);

    if(found){
        cout << val << " is present in the linked list " << endl;
    }
    else{
        cout << val << " is not present in the linked list " << endl;   
    }

    int total = list.count();

    cout << "Total no. of nodes " << total << endl;

    cout << "Now performing Remove operation " << endl;

    list.remove_node(4);

    cout << "Deleting 4 " << endl;

    list.printList();

    list.remove_node(3);

    cout << "Deleting 3 " << endl;

    list.printList();

    list.remove_node(10);

    cout << "Deleting 10 " << endl;

    list.printList();

    return 0;
}