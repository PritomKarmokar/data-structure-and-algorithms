/*
    Insertion operation in doubly linked list
    01. Inserting at the head node.
    02. Inserting at the last node (2 approaches).
    03. Inserting at a given index.
    04. Inserting a node after a given node.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;

    // Default constructor where the 'val' of the node is given
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }

    // Default constructor where the 'val', 'next' and 'prev' pointer of the node is given
    Node(int val, Node *next, Node *prev)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};


class doubLinkedList{
    Node *head;
    Node *tail; 
    int size;
public:

    // Default constructor
    doubLinkedList()
    {
        this->size = 0;
    }
    
    // Utility function for adding an item at the head node
    void prepend(int val)   // 'prepend' means adding at the first
    {
        Node *node = new Node(val);

        node->next = head;
        if(head != NULL){       // If 'head' == NULL that means the list is currently empty
            head->prev = node;
        }
        node->prev = NULL;
        head = node;

        if(tail == NULL){
            tail = head;
        }

        size += 1;
    }

    // Utility function for inserting an item at the last node
    void insertLast(int val)
    {
        if(head == NULL){   // If the linked list is empty then it'll be the head node
            prepend(val);
            return;
        }

        Node *node = new Node(val);
        node->next = NULL;

        tail->next = node;
        node->prev = tail;
        tail = node;

        size += 1;
    }

    // Utility function for inserting an item at the last node
    // We're asumming that 'tail' pointer is not given by default.
    void insertLast2(int val)
    {
        Node *node = new Node(val);
        node->next = NULL; // Since it'll be the new last node so, it'll point next to 'NULL'

        if(head == NULL){   // If the linked list is empty
            head = node;
            node->prev = NULL;
            return;
        }

        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }

        node->prev = last;
        last->next = node;

        size += 1;
        // In this 'tail' node will be the same as previous cause we're assuming 'tail' is not given to us
    }

    // Utility function for inserting an item at the given index
    void insertAtIndex(int val, int index)
    {   
        cout << "Inserting " << val << " at the index " << index <<endl;

        // Inserting at the head
        if(index == 0){
            // cout << "Ok before prepend" << endl;
            prepend(val);
            return;
        }

        // Inserting at the end
        if(index == size){
            insertLast(val);
            return;
        }   

        Node *node = new Node(val);

        Node *temp = head;
        //cout << "cur temp->head = " << temp->val << endl;
        for(int i = 1; i < index; i++){
            temp = temp->next;
        }

        Node *prev_node = temp;
        Node *next_node = prev_node->next;

        // Now adding pointer to these nodes
        prev_node->next = node;
        node->prev = prev_node;
        node->next = next_node;
        next_node->prev = node;

    }


    // Utility function for adding an item after a given node
    void insertAfterNode(int nodeVal , int val)
    {
        Node *temp = searchByValue(nodeVal);

        if(temp == NULL){
            cout << "The " << nodeVal << " is not presented in the linked list" << endl;
            return;
        }

        cout << "Inserting " << val << " after node " << nodeVal << endl;

        Node *node = new Node(val);
        Node *prev_node = temp;
        Node *next_node = prev_node->next;

        prev_node->next = node;
        node->prev = prev_node;

        if(next_node != NULL){      // In the case when we're adding a node after the last node, then we need to handle 'NULL pointer' exception
            next_node->prev = node;
            node->next = next_node;
        }
    }


    // Utility function for searching an item based on the value
    Node *searchByValue(int val)
    {
        Node *cur = head;

        while(cur != NULL){
            if(cur->val == val){    // If the 'val' of the node is present then return it
                return cur;
            }
            cur = cur->next;
        }

        return NULL;
    }

    //Utility function for searching a node based on the index
    Node *searchByIndex(int index)
    {   
        if(index > Size()){
            return NULL;
        }

        Node *temp = head;

        for(int i = 0; i < index; i++){
            // cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;

        return temp;
    }

    // Utility function for displaying the values of the doubly linked list
    void displayList()
    {
        if(head == NULL){
            cout << "The doubly linked list is empty !!" << endl;
            return;
        }

        cout << "Elements of the doubly linked list are : ";
        Node *cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n\n";
    }

    // Utility function for displaying the values of the doubly linked list in reverse order
    void displayListRev()
    {
        if(head == NULL){
            cout << "The doubly linked list is empty !!" << endl;
            return;
        }

        // First moving towards the last node from the first node
        Node *cur = head;
        Node *last = NULL;

        while(cur != NULL){
            last = cur;
            cur = cur->next;
        }

        cout << "Elements of the doubly linked list (reverse order) are: ";

        while(last != NULL){
            cout << last->val << " ";
            last = last->prev;
        }

        cout << "\n\n";
    }

    // Utility function for displaying the value of the head.
    void displayHead()
    {
        if(head == NULL){
            cout << "Head is null !!" << endl;
            return;
        }

        cout << "Value of the head = " << head->val << endl;
    }

    // Utility function for displaying the value of the head.
    void displayTail()
    {
        if(tail == NULL){
            cout << "'Tail' node is null !!" << endl;
            return;
        }

        cout << "Value of the tail = " << tail->val << endl;
    }

    // Utility function returning the size of the linked list.
    int Size()
    {
        return size;
    }
};

int main()
{   
    doubLinkedList *d1 = new doubLinkedList();
    int value, index, nodeVal;

    // Inserting value '10' at the head node
    value = 10;
    d1->prepend(value);
    d1->displayHead();
    d1->displayTail();
    d1->displayList();

    // int size = d1->displaySize();

    // cout << "Size of the linked list : " << size << endl;

    // Inserting value '20' at the starting of the linked list
    value = 20;
    d1->prepend(value);
    d1->displayHead();
    d1->displayTail();
    d1->displayList();


    // Inserting value '30' at the end of the linked list
    value = 30;
    d1->insertLast(value);
    d1->displayListRev();
    d1->displayHead();
    d1->displayTail();
    d1->displayList();

    int length = d1->Size();  
    cout << "Length of the linked list : " << length << endl;  
    d1->displayList();

    // Inserting value '40' at the index 2
    value = 40;
    index = 2;
    d1->insertAtIndex(value, index);
    d1->displayHead();
    d1->displayTail();
    d1->displayList();


    
    // Node *n = d1->searchByIndex(4);
    // if(n == NULL) cout << "Index is out of range" << endl;
    // else cout << n->val << endl;
    // value = 50;
    // Node *node = d1->searchByValue(value);
    // if(node == NULL){
    //     cout << "node is not presented in the linked list" << endl;
    // }
    // else cout << "node is presented in the linked list" << endl;


    // Inserting '50' after node '10'
    value = 50;
    nodeVal = 10;
    d1->insertAfterNode(nodeVal, value);
    d1->displayHead();
    d1->displayTail();
    d1->displayList();


    // Inserting '60' after node '30'
    value = 60;
    nodeVal = 30;
    d1->insertAfterNode(nodeVal, value);
    d1->displayHead();
    d1->displayTail();
    d1->displayList();
    
    return 0;
}