#include <stdio.h>
#include <stdlib.h>
#include "dump.h"
+
void dump_print(int* addr, const char* name, FILE * point_to_file);
void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file);
void dump_align(FILE * point_to_file);
void dump_connection(FILE * point_to_file, Data_list* list);

void dump(Data_list* list)
{
    const char* fname = "data.dot";

    FILE * point_to_file = fopen(fname, "w");

    if (!point_to_file)
    {
        printf("The file does not open\n");

        exit(EXIT_FAILURE);
    }
    
    fprintf(point_to_file, "digraph G{\n rankdir = LR;\n bgcolor = grey;\n node[color = blue, fontsize = 10];\n edge[color = blue, fontsize = 15];\n");
    fprintf(point_to_file, "subgraph cluster_list {\n node[style = filled, color = white, fontsize = 10];\n edge[color = blue, fontsize = 15];\n style = dashed;");
    fprintf(point_to_file, "color = black;");

    for(int i = 0; i < INITIAL_SIZE_DATA; i++)
    {
        dump_print(i, list->prev, list->data, list->next, point_to_file);    
    }

    dump_align(point_to_file);

    dump_connection(point_to_file, list);

    fprintf(point_to_file, "\n}\n}");

    fclose(point_to_file);
}

void dump_print(int i, int* prev, int* data, int* next, FILE * point_to_file)
{
    fprintf(point_to_file,"[shape = Mrecord, style = filled, fillcolor = white, color = blue, label = \" DATA: %d | NXT: %d | PRV: %d \"];\n", data[i], next[i], prev[i]);
   
}

void dump_align(FILE * point_to_file)
{
    for(int i = 0; i < INITIAL_SIZE_DATA - 1; i++)
    {
        fprintf(point_to_file, "%d ->", i);
    }

    fprintf(point_to_file, "%d [weight = 10000, color = invis];\n", INITIAL_SIZE_DATA - 1);
}

void dump_connection(FILE * point_to_file, Data_list* list)
{
    int i = 2;
    int index = search_index_of_value(0, list->prev);
    int index_bef = 0;

    while(list->next[index] != 0)
    {
        i++;

        index_bef = index;

        index = search_index_of_value(i, list->next);

        fprintf(point_to_file, "%d -> %d [color = blue, weight = 0]\n", index_bef, index);
    }
    
}

void Insert(Node* node)
{
    int* parrent = 0;

    while(node != NULL)
    {
        parrent = node;

        node = (value < node->data)? node->left:node->right;
    }
    node_ctor(parrent);
}