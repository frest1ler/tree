#include <stdio.h>
#include <stdlib.h>
#include "tree_create.h"

int* get_pointer_tree()
{
    int* node = (int*)calloc(1, sizeof(Node));

    if (node == NULL)
    {
        printf("Memory allocation failed\n");

        return NULL;
    }

    return node;
}

void tree_destroy(int*  node)
{
    if (list->data != NULL)
    {
        free(list->data);
    }
    else
    {
        printf("NULL pointer list->data\n");
    }

    if (list->next != NULL)
    {
        free(list->next);
    }
    else
    {
        printf("NULL pointer list->next\n");
    }

    if (list->prev != NULL)
    {
        free(list->prev);
    }
    else
    {
        printf("NULL pointer list->prev\n");
    }

    if (list != NULL)
    {
        free(list);
    }
    else
    {
        printf("NULL pointer list\n");
    }
}
void tree_ctor(int* pointer)
{
    Node* node  = (Node*)calloc(1, sizeof(Node));

    pointer = &node;
}