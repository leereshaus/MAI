#include <iostream>
#include "figure.h"

Figure::Figure(double q, double w, double e, double r, double t) {
    x = q;
    y = w;
    a = e;
    b = r;
    h = t;
    S = (a + b) * h / 2;
}

void Figure::print_square() {
    std::cout << "Square S = " << S << std::endl;
    return;
}

void Figure::center() {
    double center_x = x + a / 2;
    double center_y = y + h / 2;
    std::cout << "Coordinates: x = " << center_x << "; y = " << center_y << std::endl;
    return;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    std::cout << "Coordinates of point A: x = " << fig.x << "; y = " << fig.y << std::endl;
    std::cout << "Length a = " << fig.a << std::endl;
    std::cout << "Length b = " << fig.b << std::endl;
    std::cout << "High h = " << fig.b << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    int k = 1;
    while (k) {
        std::cout << "Input A, a, b, h" << "\n";
        is >> fig.x;
        is >> fig.y;
        is >> fig.a;
        is >> fig.b;
        is >> fig.h;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Incorrect input. Try again" << std::endl;
            k = 1;
        }
        else {
            std::cin.ignore(32767, '\n');
            if ((fig.a > 0) && (fig.b > 0))
                k = 0;
            else {
                std::cout << "Incorrect input. Try again" << std::endl;
                k = 1;
            }
        }
    }
    return is;
}
bool operator== (const Figure& f1, const Figure& f2)
{
    return ((f1.x == f2.x) && (f1.y == f2.y) && (f1.a == f2.a) && (f1.b == f2.b) && (f1.h == f2.h));
}
Figure& Figure::operator=(const Figure& right) {
    if (this == &right) {
        return *this;
    }
    this->x = right.x;
    this->y = right.y;
    this->a = right.a;
    this->b = right.b;
    this->h = right.h;
    return *this;
}
