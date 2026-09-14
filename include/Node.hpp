#pragma once

template <typename T>
class Node {
private:
    T value;
    Node<T>* next;

public:
    Node(T val);
    T getValue() const;
    Node<T>* getNext() const;
    void setNext(Node<T>* next);
};

#include "Node.tpp"