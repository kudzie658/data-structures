#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

template<typename T>
class Linkedlist
{
private:
    Node<T>* list;   // head
    int size;

    void update_positions();

public:
    Linkedlist(T data);
    ~Linkedlist();

    bool add(T data);
    bool insert(T data, int pos);
    bool remove(T data);
    bool removeAt(int pos);
    bool find(T element) const;
    Node<T>* findNode(T data);
    void display() const;
    bool clear();

    inline int getSize() const { return size; }
};

// -------------------- Constructor --------------------

template<typename T>
Linkedlist<T>::Linkedlist(T data) : size(1) {
    list = new Node<T>(data, 1);
}

// -------------------- Destructor --------------------

template<typename T>
Linkedlist<T>::~Linkedlist() {
    clear();
}

// -------------------- Add at end --------------------

template<typename T>
bool Linkedlist<T>::add(T data) 
{
    Node<T>* new_node = new Node<T>(data, size + 1);

    Node<T>* current = list;
    while (current->next)
        current = current->next;

    current->next = new_node;
    size++;

    return true;
}

// -------------------- Insert at position --------------------

template<typename T>
bool Linkedlist<T>::insert(T data, int pos)
{
    if (pos < 1 || pos > size + 1)
        return false;

    Node<T>* new_node = new Node<T>(data, pos);

    // insert at head
    if (pos == 1)
    {
        new_node->next = list;
        list = new_node;
    }
    else
    {
        Node<T>* current = list;
        for (int i = 1; i < pos - 1; i++)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
    }

    size++;
    update_positions();
    return true;
}

// -------------------- Remove by value --------------------

template<typename T>
bool Linkedlist<T>::remove(T data)
{
    if (!list)
        return false;

    // remove head
    if (list->data == data)
        return removeAt(1);

    Node<T>* current = list;

    while (current->next && current->next->data != data)
        current = current->next;

    if (!current->next)
        return false; // not found

    Node<T>* del = current->next;
    current->next = del->next;
    delete del;

    size--;
    update_positions();
    return true;
}

// -------------------- Remove at position --------------------

template<typename T>
bool Linkedlist<T>::removeAt(int pos)
{
    if (pos < 1 || pos > size)
        return false;

    // remove head
    if (pos == 1)
    {
        Node<T>* old = list;
        list = list->next;
        delete old;
        size--;
        update_positions();
        return true;
    }

    Node<T>* current = list;

    for (int i = 1; i < pos - 1; i++)
        current = current->next;

    Node<T>* del = current->next;
    current->next = del->next;
    delete del;

    size--;
    update_positions();
    return true;
}

// -------------------- Update positions --------------------

template<typename T>
void Linkedlist<T>::update_positions()
{
    Node<T>* current = list;
    int pos = 1;
    while (current)
    {
        current->position = pos++;
        current = current->next;
    }
}

// -------------------- Find by value --------------------

template<typename T>
bool Linkedlist<T>::find(T element) const
{
    Node<T>* current = list;
    while (current)
    {
        if (current->data == element)
            return true;
        current = current->next;
    }
    return false;
}

// -------------------- Get node by value --------------------

template<typename T>
Node<T>* Linkedlist<T>::findNode(T data)
{
    Node<T>* current = list;
    while (current)
    {
        if (current->data == data)
            return current;
        current = current->next;
    }
    return nullptr;
}

// -------------------- Display list --------------------

template<typename T>
void Linkedlist<T>::display() const
{
    Node<T>* current = list;
    while (current)
    {
        std::cout << "[" << current->position << "] " 
                  << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

// -------------------- Clear list --------------------

template<typename T>
bool Linkedlist<T>::clear()
{
    Node<T>* current = list;
    while (current)
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    list = nullptr;
    size = 0;
    return true;
}

#endif // LINKEDLIST_HPP