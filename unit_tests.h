/* 
 * unit_tests.h 
 * 
 * CS 15 homework 3
 * by Edward Kusel, November 2021
 * 
 * Uses Matt Russell's unit_test framework to test BinarySearchTree
 */

#include <cassert>
#include "BinarySearchTree.h"

using namespace std;

/********************************************************************\
*                             BinarySearchTree TESTS                 *
\********************************************************************/

/* default constructor test
 * initialize a BST, check for errors at runtime
 */
// void constructor()
// {
//     BinarySearchTree bst;
// }
/* tree_height test, also tests max_helper
 * initialize an empty BST, check that height is -1
 * initialize nonempty BST with duplicate values and check that height is
 * correctly reported
 */
// void tree_height()
// {
//     BinarySearchTree bst;
//     assert(bst.tree_height() == -1);
//     bst.insert(5);
//     assert(bst.tree_height() == 0);
//     bst.insert(2);
//     bst.insert(4);
//     bst.insert(8);
//     bst.insert(9);
//     bst.insert(9);
//     assert(bst.tree_height() == 2);
//     bst.print_tree();
// }
/* contains test
 * initialize an empty BST, check that a random value is correctly reported as
 * not contained. Fill the BST, and check that inserted values are correctly
 * reported as contained.
 */
// void contains()
// {
//     BinarySearchTree bst;
//     assert(bst.contains(9708) == false);
//     bst.insert(2);
//     assert(bst.contains(2));
//     bst.insert(5);
//     assert(bst.contains(2));
//     assert(bst.contains(5));
    
// }
/* insert test
 * fill a BST with random values including a duplidate, check that values are
 * properly inserted and the duplicate is correctly reported.
 */
// void insert()
// {
//     BinarySearchTree bst;
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     bst.insert(11);
//     bst.insert(12);
//     bst.insert(1);
//     bst.insert(68);
//     bst.print_tree();
// }
/* post_order_delete test
 * fill a BST with random values, check that memory leak issues are resolved
 * due to post_order_delete being called in destructor
 */
// void post_order_delete()
// {
//     BinarySearchTree bst;
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     bst.insert(11);
//     bst.insert(12);
//     bst.insert(1);
//     bst.insert(68);
// }

/* assignment_operator_overload and pre_order_copy test
 * initialize two BST instances, fill one and set the empty BST equal to the
 * filled BST, check that the tree is correctly copied. Try copying an empty
 * and a nonempty tree.
 *
 * Note: this tests both the assignment operator overload function AND the
 *       pre_order_copy function
 */
// void assignment_operator_overload()
// {
//     BinarySearchTree bstOne;
//     BinarySearchTree bstTwo;

//     // self assignment
//     bstOne = bstOne;

//     // fill bstOne
//     bstOne.insert(3);
//     bstOne.insert(4);
//     bstOne.insert(2);
//     bstOne.print_tree();
//     // invoke assignment operator overload function by setting bstTwo equal
//     // to bstOne
//     bstTwo = bstOne;
//     // print to check that bstOne was correctly copied by bstTwo
//     bstTwo.print_tree();

//     // set bstTwo equal to an empty tree
//     BinarySearchTree bstThree;
//     bstTwo = bstThree;
//     bstTwo.print_tree();
//     // check that bstTwo is now empty
//     assert(bstTwo.tree_height() == -1);

// }

/* find_min test
 * check that find_min returns the largest possible integer for an empty tree,
 * and that find_min returns the minimum value for a filled BST
 */
// void find_min()
// {
//     BinarySearchTree bst;
//     cout << "CALLED ON EMPTY TREE: " << bst.find_min() << endl;
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     assert(bst.find_min() == 1);
// }
/* find_max test
 * check that find_max returns the smallest possible integer for an empty tree
 * and that find_max returns the maximum value for a filled BST
 */
// void find_max()
// {
//     BinarySearchTree bst;
//     cout << "CALLED ON EMPTY TREE: " << bst.find_max() << endl;
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     assert(bst.find_max() == 10);
// }
/* node_count test
 * Initialize empty BST, check that node_count is zero, then fill the BST
 * and check that the correct number of nodes is returned, then duplicate
 * each node and ensure node_count returns the same number of nodes as before
 */
// void node_count()
// {
//     BinarySearchTree bst;
//     assert(bst.node_count() == 0);
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     assert(bst.node_count() == 4);
//     // duplicate each node
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     // ensure node_count remains the same
//     assert(bst.node_count() == 4);
// }
/* count_total test
 * Initialize empty BST, check that zero is returned, then fill the BST
 * and check that the correct sum is returned, then duplicate
 * each node and ensure count_total returns double the former sum
 */
// void count_total()
// {
//     BinarySearchTree bst;
//     assert(bst.count_total() == 0);
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     assert(bst.count_total() == 16);
//     // duplicate each node
//     bst.insert(2);
//     bst.insert(10);
//     bst.insert(1);
//     bst.insert(3);
//     // ensure count_total doubles
//     assert(bst.count_total() == 32);
// }
/* remove_empty_case test
 * initialize an empty bst, call remove and check that false is returned
 */
// void remove_empty_case()
// {
//     BinarySearchTree bst;
//     assert(bst.remove(1) == false);
// }
/* remove_duplicate_case test
 * fill a bst including a duplicate, call remove on the duplicated node and
 * check that only the count is reduced by one.
 */
// void remove_duplicate_case()
// {
//     BinarySearchTree bst;
//     bst.insert(8);
//     bst.insert(4);
//     bst.insert(1);
//     bst.insert(1);
//     bst.insert(4);
//     bst.insert(12);
//     bst.print_tree();
//     cout << "NODE_COUNT: " << bst.node_count() << endl;
//     assert(bst.remove(1) == true);
//     cout << "NODE_COUNT: " << bst.node_count() << endl;
//     bst.print_tree();
// }
/* remove_leaf_case_one test (root case)
 * initialize a one-node bst and remove the single node (root), check that
 * the root is properly removed
 */
// void remove_leaf_case_one()
// {
//     BinarySearchTree bst;
//     bst.insert(2);
//     bst.print_tree();
//     assert(bst.remove(2) == true);
//     bst.print_tree();
// }
/* remove_leaf_case_two test
 * initialize a non-empty bst and try removing a leaf that is left of a
 * given node. Check that the leaf is properly removed.
 */
// void remove_leaf_case_two()
// {
//     BinarySearchTree bst;
//     bst.insert(5);
//     bst.insert(2);
//     bst.insert(6);
//     bst.print_tree();
//     assert(bst.remove(2) == true);
//     bst.print_tree();
// }
/* remove_leaf_case_three test
 * initialize a non-empty bst and try removing a leaf that is right of a
 * given node. Check that the leaf is properly removed.
 */
// void remove_leaf_case_three()
// {
//     BinarySearchTree bst;
//     bst.insert(5);
//     bst.insert(2);
//     bst.insert(6);
//     bst.print_tree();
//     assert(bst.remove(6) == true);
//     bst.print_tree();
// }
/* remove_one_child_case test
 * initialize a non-empty bst and try removing a node with one child.
 * Check that the node is properly removed. Check cases where the node
 * to be removed has one left child or one right child and for the root
 * case for each of the former cases.
 */
// void remove_one_child_case()
// {
    // BinarySearchTree bst;
    // // node to be removed has one left child
    // bst.insert(4);
    // bst.insert(3);
    // bst.insert(2);
    // bst.print_tree();
    // assert(bst.remove(3) == true);
    // bst.print_tree();
    // root case for one left child
    // BinarySearchTree bstTwo;
    // bstTwo.insert(4);
    // bstTwo.insert(3);
    // bstTwo.print_tree();
    // bstTwo.remove(4);
    // bstTwo.print_tree();
    // // node to be removed has one right child
    // BinarySearchTree bstThree;
    // bstThree.insert(4);
    // bstThree.insert(5);
    // bstThree.insert(6);
    // bstThree.print_tree();
    // assert(bstThree.remove(5) == true);
    // bstThree.print_tree();
    // // root case for one right child
    // assert(bstThree.remove(4) == true);
    // bstThree.print_tree();
// }
/* remove_two_child_case test
 * initialize a non-empty bst and call remove on a node with two children.
 * Check that node is properly removed and proper minimum value in the 
 * right subtree takes the removed node's place.
 *
 */
// void remove_two_child_case()
// {
//     BinarySearchTree bst;
//         int values[]  = {4, 2, 11, 15, 9, 1, -6, 5, 3, 15, 2, 5, 13, 14};
//         int numValues = sizeof(values) / sizeof(int);
//         for (int i = 0; i < numValues; i++) {
//                 bst.insert(values[i]);
//         }
//         // check that entire min value in right subtree is removed once
//         // moved even if its count is greater than one
//         bst.insert(13);
//         bst.insert(13);
//         bst.print_tree();
//         bst.remove(11);
//         bst.print_tree();
// }




