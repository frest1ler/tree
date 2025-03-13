#include <stdio.h>
#include <stdlib.h>
#include "tree_create.h"

Node* get_pointer_node() {
    Node* node = (Node*)calloc(1, sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed : node\n");
        return NULL;
    }

    return node;
}

Node* node_ctor(Node* node, int value, Node* parent)
{
    Node* node = get_pointer_node();

    node->data    = value ;
    node->parent  = parent;
    node->pointer = node  ;

    return node;
}

void node_destroy(Node* node) {
    if (node == NULL) {
        printf("NULL pointer node\n");
        return;
    }

    if (node->left != NULL){
        free(node->left);
    }

    if (node->right != NULL){
        free(node->right); 
    }
    free(node);
}

Tree* ctor_tree()
{
    Tree* tree = (Tree*)calloc(1, sizeof(Tree));

    if (tree == NULL) {
        printf("Memory allocation failed: Tree\n");
        return NULL;
    }

    Node* node = get_pointer_node();

    tree->root = node;

    return tree;
}