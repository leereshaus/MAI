/*Гусева С. Р. М8О-201Б-20
Вариант 14: структура данных - бинарное дерево*/

#include <iostream>
#include "figure.h"
#include "tree.h"

int prov() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Incorrect input" << std::endl;
        return 0;
    }
    else {
        std::cin.ignore(32767, '\n');
        return 1;
    }
}

int main() {
    //setlocale(LC_ALL, "Russian");
    std::cout << "Trapezoid looks like:" << "\n";
    std::cout << "            a         " << "\n";
    std::cout << "     B------------C" << "\n";
    std::cout << "    /       |      \\ " << "\n";
    std::cout << "   /        | h     \\ " << "\n";
    std::cout << "  /         |        \\ " << "\n";
    std::cout << " A--------------------D" << "\n";
    std::cout << "            b         " << "\n";

    Figure fig(0, 0, 0, 0, 0);
    int m, number;
    Tree tree;
    root* t;
    //int index;
    while (true) {
        std::cout << "1. Create tree" << std::endl << "2. Size of tree" << std::endl << "3. Delete element of tree" << std::endl << "4. Delete tree" << std::endl << "5. Add element in tree" << std::endl << "6. Print tree" << std::endl << "7. Exit" << std::endl;
        std::cin >> m;
        if (prov()) {
            if (m == 1) {
                std::cout << "Tree is created" << std::endl;
                t = tree.head;
                tree.delete_all(t);
                tree.head = NULL;
            }
            if (m == 2){
                t = tree.head;
                //index = tree.get_maxindex(t);
                std::cout << "Size of tree: " << tree.get_maxindex(t) << std::endl;
            }
            if (m == 3) {
                t = tree.head;
                std::cout << "Input index of element" << std::endl;
                std::cin >> number;
                if (prov())
                    if ((number <= tree.get_maxindex(t)) && (number >= 1)) {
                        t = tree.head;
                        tree.head = t;
                    }
                    else
                        std::cout << "This element does not exist" << std::endl;
            }
            if (m == 4) {
                t = tree.head;
                tree.delete_all(t);
                std::cout << "Tree is deleted" << std::endl;
            }
            if (m == 5) {
                t = tree.head;
                std::cout << "Input index of new element" << std::endl;
                std::cin >> number;
                if (prov())
                    if ((number <= (tree.get_maxindex(t) + 1)) && (number >= 1)) {
                        std::cout << "Input figure" << std::endl;
                        std::cin >> fig;
                        t = tree.add_element(t, fig);
                        tree.head = t;
                    }
                    else
                        std::cout << "This figure does not exist" << std::endl;
            }
            if (m == 6)
                std::cout << tree;
            if (m == 7) {
                t = tree.head;
                tree.delete_all(t);
                return 1;
            }
        }
    }
}
