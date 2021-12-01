/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 * by Edward Kusel, November 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

/* constructor
 *    Purpose: initializes an empty tree
 *    Returns: none
 */
BinarySearchTree::BinarySearchTree()
{
        // initializes empty tree
        root = nullptr;

}
/* destructor
 *    Purpose: deletes all heap-allocated memory, clears tree
 *    Returns: none
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}
/* post_order_delete
 *    Purpose: walks tree in post-order traversal, deleting nodes as it goes
 * Parameters: Node pointer
 *    Returns: none
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        // tree is empty, nothing to do
        if (node == nullptr) {
                return;
        }
        // visit left subtree
        post_order_delete(node->left);
        // visit right subtree
        post_order_delete(node->right);
        // delete current node
        delete node;
}
/* copy constructor
 *    Purpose: uses pre-order traversal to copy the tree
 * Parameters: address of BinarySearchTree instance
 *    Returns: none
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        root = pre_order_copy(source.root);
}
/* assignment overload
 *    Purpose: checks for self-assignment when "=" operator used, deletes
 *             current tree if it exists and then uses pre-order traversal
 *             to copy the tree
 * Parameters: address of BinarySearchTree instance
 *    Returns: this pointer
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // check for self-assignment
        if (this != &source) {
                // delete current tree if it exists
                post_order_delete(root);
                // use pre-order traversal to copy the tree
                root = pre_order_copy(source.root);
        }
        return *this;
}
/* pre_order_copy
 *    Purpose: copies a tree using pre-order tree traversal
 * Parameters: Node pointer
 *    Returns: Node pointer pointing to copied tree
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        // handle empty tree
        if (node == nullptr) {
                return nullptr;
        } else {
                // create new node, copy data and count
                Node *newNode = new Node;
                newNode->data = node->data;
                newNode->count = node->count;
                // recursively call for left and right
                newNode->left = pre_order_copy(node->left);
                newNode->right = pre_order_copy(node->right);
                // return copied tree
                return newNode;
        }

}
/* find_min wrapper function
 *    Purpose: Used to enable recursion in private find_min function to return
 *             minimum value in a tree
 * Parameters: none
 *    Returns: int
 */
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX


        return find_min(root)->data;
}
/* find_min
 *    Purpose: uses recursion and BST invariant to find and return node 
 *             containing the minimum value in a tree
 * Parameters: Node pointer
 *    Returns: Pointer to node containing min value
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        // base case
        if (node->left == nullptr) {
                return node;
        // recursive call, uses BST invariant that minimum value will be
        // "furthest left"     
        } else {
                return find_min(node->left);
        }
}
/* find_max wrapper function
 *    Purpose: Used to enable recursion in private find_max function to return
 *             maximum value in a tree
 * Parameters: none
 *    Returns: int
 */
int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MAX


        return find_max(root)->data;
}
/* find_max
 *    Purpose: uses recursion and BST invariant to find and return node 
 *             containing the maximum value in a tree
 * Parameters: Node pointer
 *    Returns: Node containing max value
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        // base case
        if (node->right == nullptr) {
                return node;
        // recursive call, uses BST invariant that maximum value will be
        // "furthest right"     
        } else {
                return find_max(node->right);
        }
}
/* contains wrapper function
 *    Purpose: Used to enable recursion in private contains function to return
 *             true if tree contains a given value, false if not
 * Parameters: value
 *    Returns: bool
 */
bool BinarySearchTree::contains(int value) const
{
        if (root == nullptr) {
                return false;
        } else {
                return contains(root, value);
        }
}
/* contains
 *    Purpose: uses recursion and BST invariant to search a tree starting at
 *             a given node for a value, returns true if the tree contains the
 *             value and false otherwise
 * Parameters: Node pointer and value
 *    Returns: bool
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        // if tree is empty
        if (node == nullptr) {
                return false;
        // base case, if value equals current node's data
        } else if (value == node->data) {
                return true;
        // if value is greater than current node's data, recurse right
        } else if (value > node->data) {
                return contains(node->right, value);
        // if value is less than current node's data, recurse left
        } else if (value < node->data) {
                return contains(node->left, value);
        } else {
                return false;
        }
}
/* insert wrapper function
 *    Purpose: Used to enable recursion in private insert function to insert
 *             a given value into the tree, while maintaining
 *             the BST invariants
 * Parameters: value
 *    Returns: none
 */
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}
/* insert
 *    Purpose: uses recursion and BST invariant to insert a value into the
 *             tree, either creating a new node or incrementing the count
 *             of an existing node, all while maintaining BST invariants
 * Parameters: Node pointer to node, Node pointer to parent of node, value
 *    Returns: none
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        // node is not in tree, create new node with count of 1
        if (node == nullptr) {
                insert_node_helper(node, parent, value);
        // value is already in tree, increment count
        } else if (node->data == value) {
                node->count++;
        
        } else if (value < node->data) {
                insert(node->left, node, value);
        } else {
                insert(node->right, node, value);
        }

}
/* remove wrapper function
 *    Purpose: Used to enable recursion in private remove function to remove
 *             a given value from the tree, while maintaining
 *             the BST invariants
 * Parameters: value
 *    Returns: true if value is removed, false otherwise
 */
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}
/* remove
 *    Purpose: uses recursion and BST invariant to remove a value from the
 *             tree, either removing a node or decrementing the count
 *             of an existing node, all while maintaining BST invariants
 * Parameters: Node pointer to node, Node pointer to parent of node, value
 *    Returns: true if value is removed, false otherwise
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        // empty tree case
        if ((not contains(node, value) or (node == nullptr))) {
                return false;
        // base case
        } else if (node->data == value) {
               remove_helper(node, parent);
               return true;
        // recursive calls
        } else if (value < node->data) {
                return remove(node->left, node, value);
        } else {
                return remove(node->right, node, value);
        }
}
/* tree_height wrapper function
 *    Purpose: Used to enable recursion in private tree_height function to
 *             return tree height from the root
 * Parameters: none
 *    Returns: tree height int
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}
/* tree_height
 *    Purpose: uses recursion and BST invariant to find the longest path from
 *             a given node to a leaf
 * Parameters: Node pointer
 *    Returns: depth from a given node
 */
int BinarySearchTree::tree_height(Node *node) const
{
        // check for empty tree
        if (node == nullptr) {
                return -1;
        }
        return 
        1 + max_helper(tree_height(node->left), tree_height(node->right));
}
/* node_count wrapper function
 *    Purpose: Used to enable recursion in private node_count function to
 *             return the total number of nodes in a tree
 * Parameters: none
 *    Returns: tree height int
 */
int BinarySearchTree::node_count() const
{
        return node_count(root);
}
/* node_count
 *    Purpose: uses recursion to return the total number of nodes from a given
 *             (including current node) and all nodes beneath it
 * Parameters: Node pointer
 *    Returns: total number of nodes
 */
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr) {
                return 0;
        } else {
                return 1 + node_count(node->left) + node_count(node->right);
        }
}
/* count_total wrapper function
 *    Purpose: Used to enable recursion in private count_total function to
 *             return the sum of all values in the tree's nodes, accounting
 *             for multiplicity
 * Parameters: none
 *    Returns: int
 */
int BinarySearchTree::count_total() const
{
        return count_total(root);
}
/* count_total
 *    Purpose: uses recursion to return the sum of all values in a tree 
 *             starting at a given node, accounting for multiplicity
 * Parameters: Node pointer
 *    Returns: int
 */
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr) {
                return 0;
        } else {
                return ((node->count) * (node->data)) + 
                        count_total(node->left) + count_total(node->right);
        }
}
/* find_parent
 *    Purpose: uses recursion to find the parent of a given node
 * Parameters: Node pointer pointing to node, Node pointer pointing to child
 *    Returns: parent Node
 */
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

/********************************************************************\
*                             helper functions                       *
\********************************************************************/

/* max_helper
 *    Purpose: compares two ints, returns maximum value
 * Parameters: two ints
 *    Returns: max int
 */
int BinarySearchTree::max_helper(int one, int two) const {
        if (one >= two) {
                return one;
        } else {
                return two;
        }
}
/* insert_node_helper
 *    Purpose: creates new node, sets value, count, and pointers. Updates
 *             parent pointers depending on if value should be to the left
 *             or right of the node's parent.
 * Parameters: node, parent, value
 *    Returns: none
 */
void BinarySearchTree::insert_node_helper(Node *node, Node *parent, int value) 
{
        // new node
        node = new Node;
        // set value, count, and pointers
        node->data = value;
        node->count = 1;
        node->left = nullptr;
        node->right = nullptr;
        // update parent
        if (parent == nullptr) {
                root = node;
        } else if (value < parent->data) {
                parent->left = node;
        } else {
                parent->right = node;
        }
}
/* remove_helper
 *    Purpose: facilitates the remove function
 * Parameters: two Node pointers
 *    Returns: bool, true if node is removed, false otherwise
 */
bool BinarySearchTree::remove_helper(Node *node, Node *parent)
{
        // duplicate case
        if (node->count > 1) {
                node->count--;
                return true;
        } 
        // leaf case
        else if (is_leaf(node)) {
                return delete_leaf(node, parent);
        }
        // one-child case: node to be removed has one child
        else if (is_one_child(node)) {
              return one_child_helper(node, parent);
        }
        // two-child case: node to be removed has two children
        else {
                return two_child_helper(node);
        }
}
/* one_child_helper
 *    Purpose: facilitates the removal of a node with one child
 * Parameters: two Node pointers
 *    Returns: bool, true if node is removed, false otherwise
 */
bool BinarySearchTree::one_child_helper(Node *node, Node *parent)
{
        if (node->left == nullptr) {
                // node is root case
                if (node == root) {
                        root = node->right;
                } else if (parent->right == node) {
                        parent->right = node->right;
                } else {
                        parent->left = node->right;
                }
                delete node;
                return true;
        } else if (node->right == nullptr) {
                // node is root case
                if (node == root) {
                        root = node->left;
                } else if (parent->right == node) {
                        parent->right = node->left;
                } else {
                        parent->left = node->left;
                }
                delete node;
                return true;
        }
        return false;
}
/* two_child_helper
 *    Purpose: facilitates the removal of a node with two children
 * Parameters: Node pointer
 *    Returns: bool, true if node is removed, false otherwise
 */
bool BinarySearchTree::two_child_helper(Node *node)
{       
        Node *minRightSub = find_min(node->right);

        node->data = minRightSub->data;
        node->count = minRightSub->count;

        // count set to one to ensure remove function removes the 
        // node rather than simply reducing the count
        minRightSub->count = 1;
        
        return remove(node->right, node, minRightSub->data);
        
}
/* is_leaf
 *    Purpose: checks if a node is a leaf
 * Parameters: Node pointer
 *    Returns: bool, true if node is a leaf, false otherwise
 */
bool BinarySearchTree::is_leaf(Node *node)
{
        if ((node->left == nullptr) and (node->right == nullptr)) {
                return true;
        } else {
                return false;
        }
}
/* delete_leaf
 *    Purpose: facilitates the removal of a leaf
 * Parameters: two Node pointers
 *    Returns: bool, true if node is removed, false otherwise
 */
bool BinarySearchTree::delete_leaf(Node *node, Node *parent)
{
        // root case
        if (parent == nullptr) {
                delete node;
                root = nullptr;
                return true;
        // node is left of parent
        } else if (parent->left == node) {
                delete node;
                parent->left = nullptr;
                return true;
        // node is right of parent
        } else {
                delete node;
                parent->right = nullptr;
                return true;
        }
}
/* is_one_child
 *    Purpose: checks if a node has only one child
 * Parameters: Node pointer
 *    Returns: bool, true if node has one child, false otherwise
 */
bool BinarySearchTree::is_one_child(Node *node)
{
        if ((node->left == nullptr) and (node->right != nullptr)) {
                return true;
        } else if ((node->right == nullptr) and (node->left != nullptr)) {
                return true;
        } else {
                return false;
        }
}
