#ifndef TREE_CREATE_H
#define TREE_CREATE_H

#include "tree.h"

Node* get_pointer_node();
Node* node_ctor(Node* node, int value, void* parent);
Tree* ctor_tree();

void  node_destroy(Node* node);

#endif /*TREE_CREATE_H*/