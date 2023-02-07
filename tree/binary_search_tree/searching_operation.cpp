#include<bits/stdc++.h>
typedef struct node Node;
using namespace std;

struct node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_node(int item)
{
    Node *new_node = new Node();

    new_node->data = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;

    if(child != NULL){
        child->parent = node;
    }
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;

    if(child != NULL){
        child->parent = node;
    }
}


Node *bst_insert(Node *root, Node *node)
{
    Node *parent_node, *current_node;

    if(root == NULL){
        root = node;
        return root;
    }

    parent_node = NULL;
    current_node = root;

    while(current_node != NULL){
        parent_node = current_node;

        if(node->data < current_node->data){
            current_node = current_node->left;
        }
        else{
            current_node = current_node->right;
        }
    }

    if(node->data < parent_node->data){
        add_left_child(parent_node, node);
    }
    else{
        add_right_child(parent_node, node);
    }

    return root;
}
/*
    Tree diagram for the program:
            _10_
           /    \
          5     17
         / \   /  \
        3   7 12   19
       / \
       1  4
*/
Node *create_bst()
{
    Node *root, *node;

    int i;
    int arr[] = {5, 17, 3, 7, 12, 19, 1, 4};

    root = create_node(10);

    for(int i = 0; i < 8; i++){
        node = create_node(arr[i]);
        root = bst_insert(root, node);
    }

    return root;
}

// function for printing the values of the tree
void in_order(Node *node)
{
    if(node->left != NULL){
        in_order(node->left);
    }

    cout << node->data << " ";

    if(node->right != NULL){
        in_order(node->right);
    }
}

// Function for searching an element in the binary search tree
Node *bst_search(Node *root, int item)
{
    Node *node = root;

    while(node != NULL){
        if(node->data == item)
        {
            return node;
        }

        if(item < node->data){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }

    return node;
}

int main()
{
    Node *root = create_bst();

    cout << "Traversing the tree using in-order traversal : ";

    in_order(root);

    cout << endl;

    int value;

    value = 7;

    Node *node;

    node = bst_search(root, value);

    if(node != NULL){
        cout << node->data << endl;
    }
    else{
        cout << "Node not found" << endl;
    }

    value = 8;

    node = bst_search(root, value);

    if(node != NULL){
        cout << node->data << endl;
    }
    else{
        cout << "Node not found" << endl;
    }
    
    return 0;
}