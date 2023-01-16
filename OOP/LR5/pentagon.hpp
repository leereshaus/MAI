#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

//
// Гусева Софья М80-201Б-20
//

#include <iostream>
#include <cmath>
#pragma once

const double pi = 3.14159265358;

using namespace std;

template <class T>
struct Pentagon {
    pair<T, T> point;
    T side;

    Pentagon() : point{ 0,0 }, side(0) {}
    Pentagon(T x, T y, T s): point{ x,y } {
        if (s < 0) throw "Сторона пятиугольника должна быть положительная!";
        side = s;
    }

    T Area() { return 1,25 * side*side * (cos(pi/5)) / (sin(pi/5)); }
};

template <class T>
ostream& operator<< (ostream& out, const unique_ptr<Pentagon<T>>& A) {
    out << "Вершины пятиугольника: " << "(" << A->point.first << ", " << A->point.second << ") "
        << "(" << A->point.first + A->side/2 - A->side/2*cos(3*pi/10) << ", " << A->point.second + A->side*sin(3*pi/10)/2*cos(3*pi/10) << ") "
        << "(" << A->point.first + A->side/2 << ", " << A->point.second + A->side*sin(3*pi/10)/2*cos(3*pi/10)/2 + A->side/2*cos(3*pi/10) << ") "
        << "(" << A->point.first + A->side/2 + A->side/2*cos(3*pi/10) << ", " << A->point.second + A->side*sin(3*pi/10)/2*cos(3*pi/10)/2 << ") "
        << "(" << A->point.first + A->side << ", " << A->point.second << ") "
        << "\n";
    return out;
}

template <class T>
istream& operator>> (istream& in, unique_ptr<Pentagon<T>>& A) {
    cout << "Введите координаты положения правильного пятиугольника: ";
    in >> A->point.first >> A->point.second;
    cout << "Введите сторону пятиугольника: ";
    in >> A->side;
    if (A->side < 0) throw "Сторона пятиугольника должна быть положительная!";
    return in;
}

template <class T>
void print(std::unique_ptr<Pentagon<T>>& elem) {
    std::cout << elem;
}

#endif // PENTAGON_HPP_INCLUDED
