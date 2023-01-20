/*  Tree Structure for the program :
     _ 2 _
     /   \
    7     9
   / \     \
  1  6     8
    / \   / \
   5   10 3  4

*/

#include<bits/stdc++.h>
typedef struct node Node;

using namespace std;

struct node{
    int data;
    Node *left;
    Node *right;
};

// Function for creating a new node
Node *create_node(int item)
{
    Node *new_node = new Node();

    if(new_node == NULL){
        cout << "Error! Could Not Create A New Node\n";
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Function for adding left child of a node
void add_left_child(Node *node, Node *child)
{
    node->left = child;
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;
}

Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_node(8);
    add_right_child(nine, eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);

    // Returning the head of the tree.
    return two;
}

int main()
{   
    Node *root = create_tree();

    cout << "root->data = " << root->data << endl;
    
    return 0;
}
