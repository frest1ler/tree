#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dump.h"

void dump_first_node(Tree* tree, FILE * point_to_file);
void dump_node(int number_node, Node* node, FILE * point_to_file);

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

    int i = 1;
    Node* node = (tree->root)->left;

    dump_node(i, node, point_to_file);    

    fprintf(point_to_file, "\n}\n}");

    fclose(point_to_file);
}

void dump_node(int i, Node* node, FILE * point_to_file)
{
    fprintf(point_to_file, "subgraph cluster_A_left {\nlabel=\"Левое облачко A1\";\n style=dotted;\nnode [shape=record];\n");
   
    fprintf(point_to_file, "a%d [label=\"{Parent %p | Ptr %p | Data %d | {Left %p | Right %p }}\"];\n", i, node->parent, node, node->data, node->left, node->right);
    if (i == 1){
        fprintf(point_to_file, "a -> a1 [label=\"Left\" dir=forward];\n}\n");
    }
    else{
        fprintf(point_to_file, "a%d -> a%d [label=\"Left\" dir=forward];\n}\n", i - 1, i);
    }
}

void dump_first_node(Tree* tree, FILE * point_to_file)
{
    int type = NO_BRANCHES;
    
    if ((tree->root)->data != NULL && (tree->root)->left != NULL){
        type = BRANCHES;
    }

    fprintf(point_to_file, "subgraph cluster_A {label=\"Облачко A\";style=dashed;node [shape=record];\n");

    fprintf(point_to_file, "a [label=\"{Parent %p | Ptr %p | Type %d | Data %d | {Left %p | Right %p }}\"];\n root -> a;", tree, tree->root, type, (tree->root)->data, (tree->root)->left, (tree->root)->right);
}