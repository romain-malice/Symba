#include "expression_tree.h"


struct ExprTreeNode_t {
    ExprTreeNode *parent;
    ExprTreeNode **childs;
    void *data;
};
