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

        if(tail == NULL){ // That means initially the linked list is empty
            tail = head;
        }
        
        size += 1;
    }

    // Utility function for adding an item at the 'end' of the linked list
    void append(int val)
    {
        if(tail == NULL){   // That means initially linked list is empty we need to insert the node at the head
            prepend(val);
            return;
        }

        Node *node = new Node(val);
        tail->next = node;
        tail = node;
        size++;
    }

    // Utility function for adding an item at a given index
    void insertAtIndex(int val, int index)
    {
        cout << "Inserting " << val << " at the index " << index <<endl;
        if(index == 0){
            prepend(val);
            return;
        }

        if(index == size){
            append(val);
            return;
        }

        Node *temp = head;

        for(int i = 1; i < index; i++){ // Looping before the given index
            temp = temp->next;
        }

        Node *node = new Node(val, temp->next); // Adding to 'node's next to 'temp->next'
        temp->next = node;      // linking 'temp->next' as new node

        size++;
    }

    // Utility function for deleting first element from the linked list
    int deleteFirst()
    {
        Node *temp = head;
        int val = head->val;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }

        cout << "Deleting " << val << " from the first index" << endl;

        size--;
        delete temp;

        return val;
    }

    // Utility function for deleting last element from the linked list
    int deleteLast()
    {
        if(size <= 1){
            return deleteFirst();
        }

        Node *secondLast = searchByIndex(size-2); // At the search function index is starting from 0 that's why 'size-2'
        Node *temp = tail;
        int val = tail->val;

        tail = secondLast;
        secondLast->next = NULL;

        cout << "Deleting " << val << " from the last index" << endl;

        delete temp;
        size--;

        return val;
    }

    // Another way to implement Utility function for deleting last element from the linked list
    int deleteLast2()
    {
        if(size <= 1){
            return deleteFirst();
        }

        Node *secondLast = head;
        Node *temp = tail;
        int val = tail->val;

        while(secondLast->next->next != NULL){
            secondLast = secondLast->next;
        }

        //cout << "secondLast->val : " << secondLast->val << endl;

        tail = secondLast;
        secondLast->next = NULL;

        cout << "Deleting " << val << " from the lst index" << endl;

        delete temp;
        size--;

        return val;
    }

    // Utility function for adding an item at a given index
    int deleteAtIndex(int index)
    {   

        if(index == 0){
            return deleteFirst();
        }

        if(index == size-1){
            return deleteLast();
        }

        Node *prev = searchByIndex(index-1);
        Node *cur = prev->next;  // The node we're going to remove
        int val = cur->val;

        prev->next = cur->next; // Breaking the chain

        cout << "Deleting " << val << " from the index " << index <<endl;

        delete cur;
        size--;

        return val;
    }

    // Utility function for searching a node by index
    Node *searchByIndex(int index)
    {
        Node *temp = head;

        for(int i = 0; i < index; i++){
            temp = temp->next;
        }

        return temp;
    }


    // Utility function for searching a node by it's value
    Node *searchByValue(int value)
    {
        Node *cur = head;   // Starting from the head node to iterate

        while(cur != NULL){
            if(cur->val == value){  // If we've got the value return it
                return cur;
            }
            cur = cur->next;
        }

        return NULL; // It'll return NULL cause we don't find the value
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

    // Utility function for returning the size of the linked list.
    int displaySize()
    {
        return size;
    }
};

int main()
{
    linkedList *l1 = new linkedList();
    int index , value , temp, size;
    Node *cur;

    // Adding an element at the head.
    value = 10;
    l1->prepend(value);
    l1->displayHead();      // displaying value of the 'head' node.
    l1->displayTail();      // displaying value of the 'tail' node.
    l1->displayList();

    // Adding another element at the head.
    value = 20;
    l1->prepend(value);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();

    // Adding an element at the end.
    value = 30;
    l1->append(value);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();

    // Adding an element at the end.
    value = 70;
    l1->append(value);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();
    

    // Adding an element at the index 2
    value = 15;
    index = 2;
    l1->insertAtIndex(value, index);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();


    // Adding an element at the index 4
    value = 35;
    index = 4;
    l1->insertAtIndex(value, index);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();


    // Deleting first element from the list
    temp = l1->deleteFirst();
    l1->displayHead();
    l1->displayTail();
    l1->displayList();


    // Displaying the size of the linked list
    size = l1->displaySize();
    cout << "Length of the linked list is : " << size << "\n\n";
    
    // Deleting last element from the linked list
    temp = l1->deleteLast();
    l1->displayHead();
    l1->displayTail();
    l1->displayList();


    // Deleting last element from the linked list
    temp = l1->deleteLast2();
    l1->displayHead();
    l1->displayTail();
    l1->displayList();

    // Deleting an element from the index 1
    index = 1;
    temp = l1->deleteAtIndex(index);
    l1->displayHead();
    l1->displayTail();
    l1->displayList();

    // // Deleting an element from the index 0
    // index = 0;
    // temp = l1->deleteAtIndex(index);
    // l1->displayHead();
    // l1->displayTail();
    // l1->displayList();

    // // Deleting an element from the last index 
    // index = 0;
    // temp = l1->deleteAtIndex(index);
    // l1->displayHead();
    // l1->displayTail();
    // l1->displayList();
    
    // Searching the value '10' in the linked list
    value = 10;
    cur = l1->searchByValue(value);

    if(cur){
        cout << cur->val << " is presented in the linked list \n\n";
    }
    else{
        cout << cur->val << " is not presented in the linked list \n\n";
    }


    // If the 'value' is not presented in the linked list, it's giving 'segmentation fault'. Need to fix this.

    return 0;
}