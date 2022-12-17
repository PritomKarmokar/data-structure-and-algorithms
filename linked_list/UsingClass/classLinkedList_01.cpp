#include<bits/stdc++.h>
using namespace std;

// Creating a class for 'Node'
class Node{
public:

    int val;
    Node *next;

    // Default Constructor where the 'val' for the node is given
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

    // Default Constructor where the 'val' for the node and 'next' pointer is given
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};


// Creating a class for 'linkedList'
class linkedList{
    Node *head;
    Node *tail;
    int size;
public:
    
    // Default Constructor
    linkedList(){
        this->size = 0;
    }

    // Function for adding an item at the 'start' of the linked list
    void prepend(int val)
    {
        Node *node = new Node(val);

        // Adding linked to the 'head' pointer
        node->next = head;
        head = node;

        if(tail == NULL){
            tail = head;
        }
        
        size += 1;
    }

    // Utility function for displaying the values of the linked list.
    void displayList()
    {
        if(head == NULL){
            cout << "The Linked List is empty!! \n";
            return;
        }

        cout << "Elements of the linked list are : ";

        Node *cur = head;
        while(cur != NULL){
            cout << cur->val << " ";
            cur = cur->next;
        }
        
        cout << endl;
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
};

int main()
{
    linkedList *l1 = new linkedList();

    // Adding an element at the head.
    int value = 10;
    l1->prepend(value);
    l1->displayHead();      // displaying value of the 'head' node.
    l1->displayTail();      // displaying value of the 'tail' node.

    // Adding another element at the head.
    value = 20;
    l1->prepend(value);
    l1->displayHead();
    l1->displayTail();
    return 0;
}