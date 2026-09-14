#pragma once

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
bool Stack<T>::push(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(top);
    top = newNode;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        return T{};
    }
    
    Node<T>* temp = top;
    T value = temp->getValue();
    top = top->getNext();
    delete temp;

    return value;
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        return T{};
    }
    return top->getValue();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}