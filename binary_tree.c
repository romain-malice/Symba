#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

struct Node_t {
    Node *parent;
    Node *left;
    Node *right;

    Variable *data;
    void (*freeData)(void*);
};

struct Tree_t {
    Node *root;
    size_t size;
};

typedef enum {
    SCALAR,
    MATRIX
} VariableType;

struct Variable_t {
    bool isKnown;
    void *value;
    VariableType type;
};

bool isKnown(Variable *v) {
    return v->isKnown;
}

void *getValue(Variable *v) {
    return v->value;
}

VariableType getVarType(Variable *v) {
    return v->type;
}

Tree *create() {
    // Allocate space
    Tree *tree = malloc(sizeof(Tree));
    if (!tree)
        return NULL;
    
    // Empty tree
    tree->root = NULL;
    tree->size = 0;

    return tree;
}

void freeNode(Tree *tree, Node *node) {
    // Verifying that the pointer exists
    if (!node) return;

    // Freeing the data
    node->freeData(node->data);

    // Freeing the node from its parent
    if (node->parent->left == node)
        node->parent->left = NULL;
    else if (node->parent->right == node)
        node->parent->right = NULL;
    tree->size--;

    // Recursively freeing childs
    freeNode(tree, node->left);
    freeNode(tree, node->right);
}

Node *createNode(Tree *tree, void *data, void (*freeData)(void*)) {
    // Allocate space
    Node *node = malloc(sizeof(Node));
    if (!node) exit(1);

    // Set parameters
    node->data = data;
    node->freeData = freeData;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    // Update tree info
    tree->size++;

    return node;
}

Node *createRoot(Tree *tree, void *data, void (*freeData)(void*)) {
    // Check if root node doesn't already exists
    if (tree->root)
        return NULL;

    // Create the node
    Node *root = createNode(tree, data, freeData);
    if (!root) exit(1);

    // Assign tree root
    tree->root = root;

    return root;
}

Node *createChild(Tree *tree, Node *parent, void *data, void (*freeData)(void*), bool isLeftChild) {
    // Check if child already exists
    if ((isLeftChild && parent->left) || (!isLeftChild && parent->right))
        return NULL;

    // Create the node
    Node *node = createNode(tree, data, freeData);

    // Assign the node to its parent
    node->parent = parent;
    if (isLeftChild)
        parent->left = node;
    else
        parent->right = node;

    return node;
}

Node *getParent(Tree *t, Node *n){
    if (t->root == n)
        return NULL;
    else
        return n->parent;
}

bool isEmpty(Tree *t){
    return t->size == 0;
}

bool isRoot(Tree *t, Node *n) {
    return t->root == n;
}

bool isExternal(Node *n) {
    return !(n->left || n->right);
}

bool isInternal(Node *n) {
    return n->left || n->right;
}

void *getData(Node *n) {
    return n->data;
}

Node *getRoot(Tree *t) {
    return t->root;
}

Node *getLeft(Node *n) {
    return n->left;
}

Node *getRight(Node *n) {
    return n->right;
}
