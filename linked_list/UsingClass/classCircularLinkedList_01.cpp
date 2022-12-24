/*
    Circular linked list implementation using C++.
    01. Insert a node at the last node 
    02. Delete a node from the list. (If we want to delete last node randomly it's providing error. Need to fix this)
*/
#include<bits/stdc++.h>
using namespace std;

// Creating a class for 'Node'
class Node{
public:
    int val;
    Node *next;

    // Default constructor where the value of the node is given
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};


// Creating a class for 'Circular Linked List'
class circularLinkedList{
    Node *head;
    Node *tail;
    int size;
public:

    // Default constructor
    circularLinkedList()
    {
        this->size = 0;
    }

    // Function for adding an item at the end of the linked list
    void insertLast(int val)
    {
        Node *node = new Node(val);
        
        if(head == NULL){   // If the linked list is currently empty
            head = node;
            tail = node;
            size += 1;
            return;
        }

        tail->next = node;
        node->next = head;
        tail = node;

        size += 1;
    }

    
    // Utility function for removing an item from the circular linked list
    void deleteNode(int val)
    {
        cout << "Deleting " << val << " from the linked list" << endl;

        if(size == 1){  // If only one node is presented in the circular linked list
            Node *temp = head;
            head = NULL;
            tail = NULL;

            size -= 1;
            delete temp;
            return;
        }

        if(head->val == val){       // If more than one node is presented in the circular linked list
            Node *temp = head;
            head = head->next;
            tail->next = head;

            size -= 1;
            delete temp;
            return;
        }

        Node *prev = head;      
        do{
            if(prev->next->val == val){
                cout << "value = " <<  prev->next->val << endl;
                break;
            }
            prev = prev->next;
        }while(prev != head);

        Node *cur = prev->next;
        Node *next_node = cur->next;
 
        if(next_node == NULL){
            tail = NULL;
            // prev->next = next_node;
        }
        else prev->next = next_node;
        
        delete cur;
        size -= 1;
    }

    // Another Utility function for removing an item from the circular linked list
    void deleteNode2(int val)
    {
        Node *node = head;
        if(node == NULL){
            return;
        }

        if(node->val == val){
            head = head->next;
            tail->next = head;

            size -= 1;
            return ;
        }

        do{
            Node *n = node->next;
            if(n->val == val){
                node->next = n->next;
                break;
            }

            node = node->next;
        }while(node != head);

        size -= 1;
    }

    // Function for displaying values of the circular linked list
    void displayList()
    {
        if(head == NULL){
            cout << "The Circular Linked List is empty" << endl;
            return;
        }

        cout << "Elements of the circular linked list are : ";

        if(size == 1){  // If the circular linked list having just one element it is providing 'Segmentation fault'. Need to fix this.
            cout << head->val;
            cout << "\n\n";
            return;
        }
        else{
            Node *node = head;

            do{
                cout << node->val << " ";
                node = node->next;

            }while(node != head);

            
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
    circularLinkedList *c1 = new circularLinkedList();
    int value;

    // Inserting value '10' at the end of the linked list
    value = 10;
    c1->insertLast(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    // Inserting value '20' at the end of the linked list
    value = 20;
    c1->insertLast(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    // Inserting value '30' at the end of the linked list
    value = 30;
    c1->insertLast(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    // Deleting value '10' from the circular linked list
    value = 10;
    c1->deleteNode(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    value = 20;
    c1->deleteNode2(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    value = 30;
    c1->deleteNode(value);
    c1->displayHead();
    c1->displayTail();
    c1->displayList();

    return 0;
}