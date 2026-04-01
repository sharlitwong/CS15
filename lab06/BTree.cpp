/*
 *      BTree.cpp
 *      CS15 Lab 06: Tree Traversals
 *
 *      Implementation of BTree.h.
 * 
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Edited to follow CS15 style guide.
 *                 Added comments for clarity.
 *                 Removed isEmpty() function.
 */

#include <cstdlib>
#include <queue>
#include <stack>

#include "BTree.h"

using namespace std;

/* constructor
 *    Purpose: Initialize an empty BTree.
 * Parameters: None
 *    Returns: N/A
 */
BTree::BTree()
{
    root = nullptr;
}


/* destructor
 *    Purpose: Deallocate all allocated memory for BTreeNodes.
 * Parameters: None
 *    Returns: N/A
 */
BTree::~BTree()
{
    postOrderDelete();
}


/* insert()
 *    Purpose: Insert a given value into the BTree.
 * Parameters: int v - value to insert into BTree
 *    Returns: None
 *       Note: Calls a recursive insert()
 */
void BTree::insert(int v)
{
    root = insert(root, v);
}


/* insert()
 *    Purpose: Insert a given value into the BTree.
 * Parameters: BTNode *curr - current node
 *             int v        - value to insert into BTree
 *    Returns: BTNode *     - the root of current tree with the value inserted
 *       Note: ALWAYS adds a leaf.
 * 
 * Implementation notes:
 *        - When the base case is reached, we are inserting the value
 *          into an empty tree, i. e., r is nullptr.
 *          In this case, we create a new leaf node with the given data
 *          value and return a pointer to that.  If the caller had a
 *          non-empty tree node, then they will set the corresponding
 *          subtree in their node to the result.
 *          DRAW THIS OUT!
 *        - Duplicate keys will go into right branch here, i. e., the
 *          left subtree contains values < node's key, right subtree
 *          contains values >= node's key.
 */
BTree::BTNode *BTree::insert(BTNode *curr, int v)
{
    /* base case: empty tree or at location of leaf node */
    if (curr == nullptr) {
        return newBTNode(v);
    /* recursive cases */
    } else if (v < curr->value) {
        curr->left = insert(curr->left, v);
        return curr;        
    } else {
        curr->right = insert(curr->right, v);
        return curr;
    }
}


/****************** inorder *****************/

/* inOrder()
 *    Purpose: Perform a in-order print of this BTree.
 * Parameters: ostream &out - output stream to output the in-ordered tree to
 *    Returns: None
 *       Note: Calls a recursive inOrder()
 */
void BTree::inOrder(ostream &out) const
{
    inOrder(root, out);
}


/* inOrder()
 *    Purpose: Perform am in-order print of the subtree rooted at given node.
 * Parameters: BTNode *curr  - root of the subtree to perform the in-order
 *                             print on
 *             ostream &out  - output stream to output the in-ordered tree to
 *    Returns: None
 */
void BTree::inOrder(BTNode *curr, ostream &out) const
{
    /* TODO: your code here */
    //base case: empty tree
    if(curr == nullptr) {
        return;
    } else {
        inOrder(curr -> left, out);
        out << curr -> value << " ";
        inOrder(curr -> right, out);
    }
}


/****************** preorder *****************/

/* preOrder()
 *    Purpose: Perform a pre-order print of this BTree.
 * Parameters: ostream &out - output stream to output the pre-ordered tree to
 *    Returns: None
 *       Note: Calls a recursive preOrder()
 * 
 * Question to ponder: Can we do this without a helper function?
 */
void BTree::preOrder(ostream &out) const
{
    preOrder(root, out);
}


/* preOrder()
 *    Purpose: Perform a pre-order print of the subtree rooted at given node.
 * Parameters: BTNode *curr  - root of the subtree to perform the pre-order
 *                             print on
 *             ostream &out  - output stream to output the pre-ordered tree to
 *    Returns: None
 *       Note: Uses a stack from the STL rather than the C++ run time stack.
 */
void BTree::preOrder(BTNode *curr, ostream &out) const
{
    if (curr == nullptr) { //curr left right
        return;
    }

    std::stack<BTNode*> stk;
    stk.push(curr);

    while (!stk.empty()) {
        BTNode *node = stk.top();
        stk.pop();

        out << node->value << " ";

        if (node->right != nullptr) {
            stk.push(node->right);
        }

        if (node->left != nullptr) {
            stk.push(node->left);
        }
    }

}


/****************** level-order *****************/

/* levelOrder()
 *    Purpose: Perform a level-order print of this BTree.
 * Parameters: ostream &out - output stream to output the level-ordered tree to
 *    Returns: None
 *       Note: Calls a recursive levelOrder()
 */
void BTree::levelOrder(ostream &out) const
{
    levelOrder(root, out);
}


/* levelOrder()
 *    Purpose: Perform a level-order print of the subtree rooted at the given 
 *             node.
 * Parameters: BTNode *curr  - root of the subtree to perform the level-order
 *                             print on
 *             ostream &out  - output stream to output the level-ordered tree
 *                             to
 *    Returns: None
 *       Note: Must be implemented using an queue
 */
void BTree::levelOrder(BTNode *curr, ostream &out) const
{
    if (curr == nullptr) {
        return;
    }

    std::queue<BTNode*> q;
    q.push(curr);

    while (!q.empty()) {
        BTNode *node = q.front();
        q.pop();

        out << node->value << " ";

        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}


/****************** postorder *****************/

/* postOrderDelete()
 *    Purpose: Perform post-order traversal to delete the entire tree.
 * Parameters: None
 *    Returns: None
 *       Note: Calls a recursive postOrderDelete()
 */
void BTree::postOrderDelete()
{
    postOrderDelete(root);
}


/* postOrderDelete()
 *    Purpose: Perform post-order traversal to delete tree rooted at given
 *             node.
 * Parameters: BTNode *curr  - root of the tree to perform the post-order
 *                             delete on
 *    Returns: None
 * 
 * Question to ponder: Could we use another traversal to delete the tree?
 */
void BTree::postOrderDelete(BTNode *curr)
{
    /* TODO: your code here */
}


/*****************************************************************************
 * A couple handy functions for creating new, initialized nodes.             *
 * We could make constructors for the struct, but let's keep things simple.  *
 *****************************************************************************/

/* newBTNode()
 *    Purpose: Create a new BTNode with given values.
 * Parameters: int v         - value that the new BTNode should have
 *             BTNode *left  - a left BTNode * to be the new BTNode's left
 *                             child 
 *             BTNode *right - a right BTNode * to be the new BTNode's right 
 *                             child
 *    Returns: BTNode * - pointer to a BTNode with the given values
 */
BTree::BTNode *BTree::newBTNode(int v, BTNode *left, BTNode *right)
{
    BTNode *newNode = new BTNode;
    newNode->value  = v;
    newNode->left   = left;
    newNode->right  = right;
    
    return newNode;
}

/* newBTNode()
 *    Purpose: Create a new BTNode.
 * Parameters: int v - value that the new BTNode should have
 *    Returns: BTNode * - pointer to a BTNode with value v and no children
 */
BTree::BTNode *BTree::newBTNode(int v)
{
    return newBTNode(v, nullptr, nullptr);
}
