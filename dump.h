#ifndef DUMP_H
#define DUMP_H

const int INITIAL_SIZE_DATA = 10;
const int NO_BRANCHES       =  0;
const int BRANCHES          =  1;

#include "tree.h"

void dump(Tree* tree, char* fname);

#endif /*DUMP_H*/