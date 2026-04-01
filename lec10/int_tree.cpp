#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/* Struct representing a node in our binary tree.
 * The tree stores integers.
 */
struct IntTreeNode {
    int data;
    IntTreeNode *child1, *child2;
};

// Functions to try implementing.
// Note: It is much easier to implement these functions recursively
int sum(IntTreeNode *node);
int size(IntTreeNode *node);
int height(IntTreeNode *node);
bool contains(IntTreeNode *node, int val);

// Helper Functions
IntTreeNode *make_example_tree();
IntTreeNode *new_node(int data, IntTreeNode *child1, IntTreeNode *child2);
IntTreeNode *new_node(int data);
void recycle_tree(IntTreeNode *root);


int main()
{
    IntTreeNode *root = make_example_tree();

    cout << "sum(root) should return 388. Received: " << sum(root) << endl;
    cout << "size(root) should return 9. Received: " << size(root) << endl;
    cout << "height(root) should return 3. Received: " << height(root) << endl;
    // print "true"/"false" rather than "1"/"0"
    cout << boolalpha;
    cout << "contains(root, 64) should return true (1). Received: "
         << contains(root, 64) << endl;
    cout << "contains(root, 19) should return false (0). Received: "
         << contains(root, 19) << endl;

    recycle_tree(root);

    return 0;
}

/* Returns  sum of all elements in the tree rooted at given node.
 * Input: pointer to node representing the root.
 * Output: Sum of all elements in tree.
 */
int sum(IntTreeNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return node->data + sum(node->child1) + sum(node->child2);
}

/* Returns number of elements in tree rooted at given node.
 * Input: pointer to node representing the root.
 * Output: Number of elements in tree.
 */
int size(IntTreeNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + size(node->child1) + size(node->child2);
}

/* Returns height of tree rooted at given node.
 * Recall: height(empty tree) is -1, height(leaf) is 0, 
 * and height(node) is the length of longest path from that node to a leaf.
 * Input: pointer to node representing the root.
 * Output: Height of tree rooted at node.
 * Note: You may also find it helpful to use the C++ maximum function `max`. 
 */
int height(IntTreeNode *node)
{
    if (node == nullptr) {
        return -1;
    } else {
        return 1 + max(height(node->child1), height(node->child2));
    }
}

/* Determines whether given tree contains given value.
 * Inputs: pointer to node representing the root, and value to search for.
 * Output: true if given tree contains val, false otherwise.
 */
bool contains(IntTreeNode *node, int val)
{
    if (node == nullptr) {
        return false;
    }
    else {
        return (node->data == val) or contains(node->child1, val) or
            contains(node->child2, val);
    }
}

/* Creates an example Tree that we can use for testing purposes.
 * Returns: pointer to root node of tree.
 * The tree will look as follows:
 *             15
 *            /  \
 *           /    \
 *          3      100
 *         / \     /  \
 *       17   99  /    \
 *               42    16
 *                    /  \
 *                   32  64
 */
IntTreeNode *make_example_tree()
{
    IntTreeNode *node32 = new_node(32);
    IntTreeNode *node64 = new_node(64);
    IntTreeNode *node16 = new_node(16, node32, node64);
    IntTreeNode *node42 = new_node(42);
    IntTreeNode *node100 = new_node(100, node42, node16);
    IntTreeNode *node17 = new_node(17);
    IntTreeNode *node99 = new_node(99);
    IntTreeNode *node3 = new_node(3, node17, node99);
    IntTreeNode *node15 = new_node(15, node3, node100);
    return node15;
}

/* Creates a new heap-allocated IntTreeNode.
 * Input: data to store in node, and pointers to nodes child1 and child2.
 * Output: Pointer to the newly created tree node.
 */
IntTreeNode *new_node(int data, IntTreeNode *child1, IntTreeNode *child2)
{
    IntTreeNode *node = new IntTreeNode;
    node->data = data;
    node->child1 = child1;
    node->child2 = child2;
    return node;
}

/* Creates a new heap-allocated IntTreeNode, with empty trees for children.
 * Input: data to store in node.
 * Output: Pointer to the newly created tree node.
 */
IntTreeNode *new_node(int data)
{
    return new_node(data, nullptr, nullptr);
}

// Recursively recycles heap memory of each node of tree.
// Input: root of tree to recycle.
void recycle_tree(IntTreeNode *root)
{
    if (root == nullptr)
        return;
    // Notice we visit the children before recycling the root. Why?
    recycle_tree(root->child1);
    recycle_tree(root->child2);
    delete root;
}
