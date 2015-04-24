#include <iostream>
#include "BST.h"

using namespace std;

MovieTree::MovieTree()
{
    root = NULL;
}


void MovieTree::Tree_InsertNUM(Movie *newNode, Movie *root){
    Movie *x = new Movie;
    x = root;

    Movie *p = new Movie;

    // make sure not at bottom of tree
    while(x != NULL){
        p = x;

        // left branch
        if (newNode->ranking < x->ranking){
            x = x->numLeft;
        }

        // right branch
        else{
            x = x->numRight;
        }
    }   

    if (newNode->ranking < p->ranking){
        p->numLeft = newNode;   
    }

    else{
        p->numRight = newNode;
    }
}

void MovieTree::Tree_InsertSTRING(Movie *newNode, Movie *root){
    Movie *x = new Movie;
    x = root;

    Movie *p = new Movie;

    // make sure not at bottom of tree
    while(x != NULL){
        p = x;

        // left branch
        if (newNode->title < x->title){
            x = x->alphaLeft;
        }

        // right branch
        else{
            x = x->alphaRight;
        }
    }   

    if (newNode->title < p->title){
        p->alphaLeft = newNode;   
    }

    else{
        p->alphaRight = newNode;
    }
}

void MovieTree::buildBSTString(Movie *root){
    Movie *traverse = new Movie; //Movie node used to move through the linked list

    for (int i = 0; i < 10; i++){ //for every linked list in the table
        traverse = &HashTable::hashTable[i]; //start at the beginning of the list

        while (traverse->next != NULL){
            if (traverse->next->title.size() > 0){ //if the title exists
                Tree_InsertSTRING(traverse->next, root);
            }
            traverse = traverse->next;
        }
    }
}
