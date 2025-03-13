#include <stdlib.h>
#include "tree.h"
#include "dump.h"
#include "tree_create.h"

int main()
{
    Tree* tree = ctor_tree();

    dump(tree, "bata.dot");

    insert(tree, 25);

    dump(tree, "bata2.dot");

    node_destroy(tree->root);

    if (tree != NULL){
        free(tree);
    }

    return 0;
}
