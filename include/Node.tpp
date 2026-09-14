#pragma once

template <typename T>
Node<T>::Node(T value) : value(value), next(nullptr) {}

template <typename T>
T Node<T>::getValue() const {
    return value;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}