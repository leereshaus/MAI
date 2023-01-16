#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "figure.h"

struct root {
    Figure data;
    root* left;
    root* right;
};

class Tree {
public:
    root* head;
public:
    Tree();
    int empty();
    void delete_all(root* tree);
    root* add_element(root* t, Figure fig);
    int get_element(int number, root* t);
    int get_maxindex(root* t);
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);
    ~Tree();
};

#endif // TREE_H_INCLUDED
