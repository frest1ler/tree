#ifndef TREE_CREATE_H
#define TREE_CREATE_H

#include "tree.h"

const int LEFT      =    0;
const int RIGHT     =    1;
const int POISON    = -333;

Node* get_pointer_node();
Node* node_ctor(int value, void* parent);
Tree* ctor_tree();

void  node_destroy(Node* node);
void  insert(Tree* tree, int value);

#endif /*TREE_CREATE_H*/