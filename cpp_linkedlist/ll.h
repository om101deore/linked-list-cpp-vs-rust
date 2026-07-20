#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
struct Node {
    T value;
    std::unique_ptr<Node> next;
};

template <class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void push(T);
    T pop();
    void traverse();

private:
    std::unique_ptr<Node<T>> head;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;  // can be omited as unique_ptr defaults to NULL
}

template <class T>
LinkedList<T>::~LinkedList() {
    std::cout << "in destructor" << std::endl;
}

template <class T>
void LinkedList<T>::push(T value) {
    std::unique_ptr<Node<int>> nn = std::make_unique<Node<T>>();

    nn->value = value;
    nn->next = std::move(head);

    head = std::move(nn);
}

template <class T>
T LinkedList<T>::pop() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty. ");
    }

    T value = head->value;
    head = std::move(head->next);

    return value;
}

template <class T>
void LinkedList<T>::traverse() {
    Node<int>* curr = head.get();

    while (curr != nullptr) {
        std::cout << curr->value << " -> ";

        curr = curr->next.get();
    }

    std::cout << "nullptr\n";
}
