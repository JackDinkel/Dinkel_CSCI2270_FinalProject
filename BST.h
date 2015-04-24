#ifndef MOVIETREE_H
#define MOVIETREE_H

#include "HashTable.h"


class MovieTree
{
    public:
        Movie *root;
        MovieTree();
        void Tree_InsertNUM(Movie *newNode, Movie *root);
        void Tree_InsertSTRING(Movie *newNode, Movie *root);
        void buildBSTString(Movie *root);
};

#endif // MOVIETREE_H