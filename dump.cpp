#include <stdio.h>
#include <stdlib.h>
#include "dump.h"

void dump_print(int* addr, const char* name, FILE * point_to_file);
void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file);
void dump_align(FILE * point_to_file);
void dump_connection(FILE * point_to_file, Node* node);
void dump_header(FILE * point_to_file, Node* node);

void dump(Node* node, char* fname)
{
    FILE * point_to_file = fopen(fname, "w");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(point_to_file, "digraph G{\n rankdir = LR;\n bgcolor = grey;\n node[color = blue, fontsize = 10];\n edge[color = blue, fontsize = 15];\n");
    fprintf(point_to_file, "subgraph cluster_node {\n node[style = filled, color = white, fontsize = 10];\n edge[color = blue, fontsize = 15];\n style = dashed;");
    fprintf(point_to_file, "color = black;");

    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        dump_print(i, node->left, node->data, node->right, point_to_file);    
    }

    dump_align(point_to_file);

    //dump_connection(point_to_file, node);

    //dump_header(point_to_file, node);

    fprintf(point_to_file, "\n}\n}");

    fclose(point_to_file);
}

void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file)
{
    fprintf(point_to_file,"%d [shape = Mrecord, style = filled, fillcolor = white, color = blue, label = \" IP: %d | DATA: %d | NXT: %d | PRV: %d \"];\n", i, i, data[i], next[i], prev[i]);
   
}

void dump_align(FILE * point_to_file)
{
    for(int i = 0; i < INITIAL_SIZE_DATA - 1; i++)
    {
        fprintf(point_to_file, "%d ->", i);
    }

    fprintf(point_to_file, "%d [weight = 10000, color = invis];\n", INITIAL_SIZE_DATA - 1);
}

// void dump_connection(FILE * point_to_file, Tree* node)
// {
//      if (point_to_file == NULL) {
//         perror("Ошибка открытия файла");
//         return;
//     }

//     int index = node->head;
//     int index_bef = 0;

//     if (index < 0){
//         return;
//     }

//     while(node->next[index] != POISON && index < INITIAL_SIZE_DATA &&
//           node->data[index] != POISON_FREE && index != index_bef && index >= 0)
//     {
//         index_bef = index;

//         index = node->next[index];

//         if (index_bef != index){
//             fprintf(point_to_file, "%d -> %d [color = blue, weight = 0];\n", index_bef, index);
//         }
//     }
//     int free      = node->next[node->free];
//     int prev_free =             node->free;

//     while(free != node->free)
//     {
//         fprintf(point_to_file, "%d -> %d [color = red, weight = 0];\n", prev_free, free);

//         prev_free =             free;
//         free      = node->next[free];
//     }
// }

// void dump_header(FILE * point_to_file, Tree* node)
// {
//     fprintf(point_to_file, "All[shape = Mrecord, label = \" HEADER | <f0> Size: %d | <f1> Head: %d | <f2> Tail: %d | <f3> Free: %d \", style = \"filled\", fillcolor = \"#ffe4c4\"];", node->size, node->head, node->tail, node->free);
//     fprintf(point_to_file, "All:<f1> -> %d [color = blue];", node->head);
//     fprintf(point_to_file, "All:<f2> -> %d [color = green];", node->tail);
//     fprintf(point_to_file, "All:<f3> -> %d [color = red];", node->free);
// }

void insert(Node* node, int value)
{   
    Node* parrent = 0;

    while(node != NULL)
    {
        parrent = node->parent;

        node = (value < node->data)? node->left:node->right;
    }
    node_ctor(node, value, parrent); //Node* node_ctor(Node* node, int value, Node* parent)
}

