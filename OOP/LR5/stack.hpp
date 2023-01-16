#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

//
//  Гусева Софья М80-201Б-20
//  Variant 6

#include <iostream>
#include <memory> // unique_ptr
#pragma once

template <class T>
struct Stack_iterator {

    using figure = T;
    using iterator_category = forward_iterator_tag;
    using value_type = unique_ptr<T>;
    using pointer = unique_ptr<T>*;
    using reference = unique_ptr<T>&;
    using difference_type = unsigned int;

    pointer it;

    Stack_iterator() {}
    Stack_iterator(pointer stack) : it(stack) {}

    void next() {
        it += 1;
    }

    reference operator*() {
        return *it;
    }

    Stack_iterator<figure>& operator++() {
        it += 1;
        return *this;
    }

    Stack_iterator<figure>& operator+(int a) {
        it += a;
        return *this;
    }

    Stack_iterator<figure>& operator-(int a) {
        it -= a;
        return *this;
    }

    bool operator!=(const Stack_iterator& rvl) {
        return it != rvl.it;
    }

};

template <class T>
struct Stack {

    using figure = T;
    using iterator = Stack_iterator<T>;
    using value_type = unique_ptr<T>;
    using pointer = unique_ptr<T>*;

    unsigned int size;
    unsigned int buffer;
    pointer stack;

    Stack() : size(0), buffer(0), stack(NULL) {}
    ~Stack() {
        delete[]stack;
    }

    void Push(value_type elem) {
        if (buffer == 0) {
            stack = new value_type[1];
            buffer = 1;
        }
        if (size == buffer) {
            value_type* temp = new value_type[buffer << 1];
            buffer <<= 1;
            for (unsigned int i = 0; i < size; ++i) {
                temp[i] = move(stack[i]);
            }
            delete[]stack;
            stack = temp;
        }
        stack[size] = move(elem);
        ++size;
    }

    void Pop() {
        if (size == 0) return;
        if(size > 0) stack[size-1] = nullptr;
        --size;
    }

    value_type Top() {
        if (size > 0) {
            return make_unique<figure>(*stack[0]);
        }
        else {
            throw "Стек пуст!";
        }
    }

    void insert(iterator it, value_type elem) {
        *it = elem;
    }

    void erase(iterator it) {
        while (it + 1 != end()) {
            *it = *(it + 1);
            it++;
        }
        size--;
    }

    iterator begin() {
        return iterator(stack);
    }

    iterator end() {
        return iterator(stack + size);
    }
};

#endif // STACK_HPP_INCLUDED
