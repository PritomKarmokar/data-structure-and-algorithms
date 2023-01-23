#include<bits/stdc++.h>
typedef struct node Node;

using namespace std;

// Declaring a structure for defining 'node' of the 'tree' data structure
struct node{
    int data;
    Node *left;
    Node *right;
};

// Function for creating a node in the 'tree' data structure
Node *create_node(int item)
{
    Node *new_node = new Node();

    if(new_node == NULL){
        cout << "ERRPR! Could not create a new node" << endl;
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Function for adding left child
void add_left_child(Node *node, Node *child)
{
    node->left = child;
}

// Function for adding right child
void add_right_child(Node *node, Node *child)
{
    node->right = child;
}

/*  
    Tree Structure for 'create_tree' function :

     _ 2 _
     /   \
    7     9
   / \     \
  1  6     8
    / \   / \
   5   10 3  4

*/

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

    // Returning the 'root' node
    return two;
}

// Function for performing pre-order traversal
void pre_order(Node *node)
{
    cout << node->data << " ";

    if(node->left != NULL){
        pre_order(node->left);
    }

    if(node->right != NULL){
        pre_order(node->right);
    }
}

// Main Function for the program starts from here.
int main()
{   
    Node *root = create_tree();

    cout << "root->data = " << root->data << endl;

    cout << "Now performing pre-order traversal of the tree : ";
    pre_order(root);

    cout << endl;

    return 0;
}