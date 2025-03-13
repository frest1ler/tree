#include "tree.h"
#include "tree_create.h"

int main()
{
    Tree* tree = ctor_tree();

    node_destroy(tree->root);

    return 0;
}
