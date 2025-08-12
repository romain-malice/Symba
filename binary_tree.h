#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef struct Node_t Node;
typedef struct Tree_t Tree;
typedef struct Variable_t Variable;

/**
 * @brief Creates a binary tree
 *
 * The tree is empty after creation.
 */
Tree *create();

/**
 * @brief Recursively frees the node and its childs.
 *
 * Removes the pointer to the node in it's parent node too.
 */
void freeNode(Tree *tree, Node *node);

/**
 * @brief Creates a Node with the given data and updates the tree size.
 *
 * Doesn't links to any other node by default.
 */
Node *createNode(Tree *tree, void *data, void (*freeData)(void*));

/**
 * @brief Creates the root node of a tree and returns it.
 * 
 * Returns NULL if there is already a root to the given tree.
 */
Node *createRoot(Tree *tree, void *data, void (*freeData)(void*));

/**
 * @brief Creates a child for a given node.
 *
 * @param tree The tree.
 * @param parent The node that will get a child.
 * @param data A pointer to the data in the node.
 * @param freeData A function that frees this data type.
 * @param isLeftChild A boolean value to know to which side we want to create the child.
 */
Node *createChild(Tree *tree, Node *parent, void *data, void (*freeData)(void*), bool isLeftChild);


Node *getParent(Tree *t, Node *n);
bool isEmpty(Tree *t);
bool isRoot(Tree *t, Node *n);
bool isExternal(Node *n);
bool isInternal(Node *n);
void *getData(Node *n);
Node *getRoot(Tree *t);
Node *getLeft(Node *n);
Node *getRight(Node *n);

#endif
