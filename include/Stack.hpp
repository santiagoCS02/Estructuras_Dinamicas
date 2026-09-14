#pragma once

#include "Node.hpp"

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack();
    ~Stack();

    bool push(T value);
    T pop();
    T peek() const;
    bool isEmpty() const;
};

#include "Stack.tpp"