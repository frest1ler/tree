#include "tree.h"
#include "tree_create.h"

int main()
{
    Node* node = get_pointer_node();

    ctor_tree(node);

    node_destroy(node);

    return 0;
}
