#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    int position;

public:
    Node() : data(), next(nullptr), position(0) {}

    Node(T data, int position = 0)
        : data(data), next(nullptr), position(position) {}

    ~Node() {
        // Do NOT delete next here!
        // The linked list class should manage deletion.
    }
};

#endif // NODE_HPP