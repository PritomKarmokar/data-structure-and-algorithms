# Tree Note Section
## Tree 
 * A tree data structure is similar to trees in our real life. But, here root lies above of all
 * Here, 7, 9 and 17 nodes are connected directly with node 2, so they are child of node 2 and node 2 is the parent node of node 2, 7 and 17
 * In the below tree, 5, 10, 19, 6, 3, 4 and 1 these nodes have no child. That's why they are known as leaf node
 
![tree_structure](https://user-images.githubusercontent.com/71670082/214832144-158f078d-e1a6-4cf4-a4c8-2f5fe5f244bb.png)

## Binary Tree
 * In these type of tree a node can only contain maximum two child nodes
 * Since, Binary tree only can contain 2 child nodes, left sided child is known as left child or left node and right sided child is known as right child or right node 

![binary_tree](https://user-images.githubusercontent.com/71670082/214847512-4f4ad81f-af38-4061-a1ec-862491276c1a.png)

 * Height of binary Tree : It is defined as the maximum depth of any leaf node from the root node.

## Tree Traversing
 * There are mainly 03 algoriths for tree traversing :
  01. Pre-order
  02. Post-order
  03. In-order

### Pre-order traversal
 * In this way, we'll first visit the root node. Then traverse the left subtree using pre-order traversal approach and after that traverse the right subtree using pre-order traversal way.

![pre_order](https://user-images.githubusercontent.com/71670082/214854345-126330ab-b3de-4a85-9c4f-e6882ff5a0c9.png)


Source code :

```
void pre_order(Node *node)
{
    cout << node->data << " ";

    if(node->left != NULL){
        pre_ordr(node->left);
    }

    if(node->right != NULL){
        pre_order(node->right);
    }
}
```

### Post-order traversal
 * In this approach, we'll first traverse left subtree using post-order approach, then traverse right subtree using the same approach and finally visit the root node.


![post_order](https://user-images.githubusercontent.com/71670082/214857627-4f02682e-e44e-4c59-94d0-48f3ff7504db.png)

Source code :

```
void post_order(Node *node)
{
    if(node->left != NULL){
        post_order(node->left);
    }

    if(node->right != NULL){
        post_order(node->right);
    }

    cout << node->data << " "; 
}
```

### In-order traversal
 * In this approach, we'll first traverse the left subtree using in-order approach, then visit the root node and after that we'll traverse the right subtree using the same approach


![in_order](https://user-images.githubusercontent.com/71670082/214858011-7e4ecc99-0ddb-4ca6-806b-4668e1792507.png)

Source code :
```
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
```

### Example Problem

![example](https://user-images.githubusercontent.com/71670082/214861254-1d730204-a14b-4424-b9f7-9cf592bc901b.png)
