#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dump.h"

void dump_first_node(Tree* tree, FILE * point_to_file);
void dump_node(Node* node, FILE * point_to_file);


int  use_left(Node* node);
int  go_left (Node* node);
void go_back (Node* node);
void bypass  (Tree* tree);

void dump(Tree* tree, char* fname)
{
    assert(tree      );
    assert(tree->root);

    FILE * point_to_file = fopen(fname, "w");

    if (!point_to_file){
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(point_to_file, "digraph G\n {rankdir=TB;\n root [label=\"Header %p\" shape=box];\n", tree);
    
    dump_first_node(tree, point_to_file);

    //Node* node = tree->root;

    bypass(tree);

    //dump_node(node, point_to_file);    

    fprintf(point_to_file, "\n}\n}");

    fclose(point_to_file);
}

void dump_node(Node* node, FILE * point_to_file)
{   
    fprintf(point_to_file, "subgraph cluster_A_left {\nlabel=\"Левое облачко A1\";\n");
    fprintf(point_to_file, "style=dotted;\nnode [shape=record];\n");
   
    fprintf(point_to_file, "a%p [label=\"{Parent %p | Ptr %p | Data %d | {Left %p | Right %p }}\"];\n", node, node->parent, node, node->data, node->left, node->right);
    
    if ((node->parent)->left == node){
    fprintf(point_to_file, "a%p -> a%p [label=\"Left\" dir=forward];\n}\n", node->parent, node);
    }
    else{
    fprintf(point_to_file, "a%p -> a%p [label=\"Right\" dir=forward];\n}\n", node->parent, node);
    }
}

void dump_first_node(Tree* tree, FILE * point_to_file)
{
    int type = NO_BRANCHES;
    
    if ((tree->root)->data != NULL && (tree->root)->left != NULL){
        type = BRANCHES;
    }

    fprintf(point_to_file, "subgraph cluster_A {label=\"Облачко A\";style=dashed;node [shape=record];\n");

    fprintf(point_to_file, "a%p [label=\"{Parent %p | Ptr %p | Type %d | Data %d | {Left %p | Right %p }}\"];\n root -> a;", tree->root,tree, tree->root, type, (tree->root)->data, (tree->root)->left, (tree->root)->right);
}

int use_left(Node* node)
{
    int count_node = 0;

    while(node->left != NULL)
    {
        node = node->left;

        count_node++;
    }
    return count_node;
}

void bypass(Tree* tree)
{
    int found_size = 0;

    Node* node = tree->root;

    while(found_size < tree->size)
    {
        found_size += go_left(node);

        go_back(node);
    }
}

int go_left(Node* node)
{   
    int add_found_size = 0;

    while(node->right != NULL || node->left != NULL)
    {
        add_found_size += use_left(node);

        node = node->right;

        add_found_size += 1;
    }
    return add_found_size;
}

void go_back(Node* node)
{
    while(node->right == NULL){
        node = node->parent;
    }
}