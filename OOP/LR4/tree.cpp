#include <iostream>
#include "tree.h"

Tree::Tree() {
    head = NULL;
};

int Tree::empty() {
    if (head == NULL)
        return 1;
    else
        return 0;
}

void Tree::delete_all(root* tree) {
    if(tree!=NULL) {
        delete_all(tree->left);
        delete_all(tree->right);
        delete tree;
    }
}

root* Tree::add_element(root* t, Figure fig) { //сбалансированное дерево
    if (t == NULL) {
        root* element = (root*)(malloc(sizeof(struct root)));
        element->data = fig;
        element->left = NULL;
        element->right = NULL;
        return element;
    }
    else if(fig.S < t->data.S) {
        t->left=add_element(t->left, fig);
    }
    else {
        t->right=add_element(t->right, fig);
    }
    return t;
}

int Tree::get_maxindex(root* t) { //обход дерева левое поддерево -> правое поддерево -> корень
    if (t == NULL) return 0;
    int i = 0;
    int g = 0;
    if (t->left != NULL) i = get_maxindex(t->left);
    if (t->right != NULL) g = get_maxindex(t->right);
    return i + g + 1;
}

int Tree::get_element(int number, root* t) {
    if (number == 1) {
        std::cout << t->data << std::endl;
        return 0;
    }
    else if (t->left != NULL) number = get_element(number - 1, t->left);
    else if (t->right != NULL) number = get_element(number - 1, t->right);
    else if (number == 0) return 0;
    else return number;
}

void print_tree_number(root* t, int k) {
    if (t->right != NULL) print_tree_number(t->right, k + 1);
    for (int i = 1; i <= k; i++){
        std::cout << "\t";
    }
    std::cout << "Figure number: " << k + 1 << std::endl;
    if (t->left != NULL) print_tree_number(t->left, k + 1);
    return;
}

void print_tree(root* t, int k) {
    if (t->right != NULL) print_tree(t->right, k + 1);
    std::cout << "Figure " << k+1 << "\n" << t->data << std::endl;
    if (t->left != NULL) print_tree(t->left, k + 1);
    return;
}

std::ostream& operator<<(std::ostream& os, const Tree& tree) {
    root* t = tree.head;
    print_tree_number (t, 0);
    print_tree (t,0);
    return os;
}

Tree::~Tree() {
    delete head;
}
