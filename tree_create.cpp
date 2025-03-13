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

Node* node_ctor(int value, Node* parent)
{
    Node* node = get_pointer_node();

    node->data    = value ;
    node->parent  = parent;
    node->pointer = node  ;

    return node;
}

void node_destroy(Node* node) 
{
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

    node->data = POISON;
    tree->root = node  ;

    return tree;
}

void insert(Tree* tree, int value)
{   
    int   branch = POISON    ;
    Node* parent = 0         ;
    Node* node   = tree->root;

    while(node != NULL && node->data != POISON)
    {
        parent = node->parent;

        if (value < node->data){
            branch = LEFT;
            node = node->left;
        }
        else{
            branch = RIGHT;
            node = node->right;
        }
    }

    if (branch == LEFT){
        node->left = node_ctor(value, parent);
    }
    else if (branch == RIGHT){
        node->right = node_ctor(value, parent);
    }
    else{ //branch == POISON
        node->data = value;
    }
    (tree->size)++;
}