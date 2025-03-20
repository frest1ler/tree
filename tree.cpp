#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "dump.h"
#include "tree_create.h"

int main()
{
    Tree* tree = ctor_tree();

    dump(tree, "bata.dot");

    printf("f_dump\n");

    insert(tree, 25);

    dump(tree, "bata2.dot");

    printf("s_dump\n");

    insert(tree, 10);

    dump(tree, "bata3.dot");

    insert(tree, 5);
    insert(tree, 4);
    insert(tree, 3);
    insert(tree, 7);
    insert(tree, 35);
    insert(tree, 45);
    //insert(tree, 26);
    
    dump(tree, "bata4.dot");

    printf("destroy\n");

    bypass_destroy(tree);

    if (tree != NULL){
        free(tree);
    }

    return 0;
}
