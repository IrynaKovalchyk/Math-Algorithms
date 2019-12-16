#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <iostream>
using namespace std;

template <typename Val>
class Node {
private:
    Val value;
    Node * next;
public:
    Node() {}

    Node(Val value, Node *next) : value(value), next(next) {}

    Val getValue() const {
        return value;
    }

    Node *getNext() const {
        return next;
    }

    void setValue(Val _value) {
        value = _value;
    }

    void setNext(Node *_next) {
        next = _next;
    }
};


#endif //LINKEDLIST_NODE_H
