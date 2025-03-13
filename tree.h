#ifndef TREE_H
#define TREE_H

struct Node
{
    int   data   ;
    void* left   ;
    void* right  ;
    void* pointer;
    void* parent ;
};

struct Tree
{
    int   size;
    void* root;
};

#endif /*TREE_H*/