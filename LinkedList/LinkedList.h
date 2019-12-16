#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
using namespace std;

#include "Node.h"
template <typename Val>

class LinkedList {
private:
    Node<Val> * head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void add (Val num){
        if (!head){
            head = new Node<Val>(num, nullptr);
        }
        else{
            Node<Val> * temp = head;
            while (temp->getNext()){
                temp = temp->getNext();
            }
            temp->setNext(new Node<Val>(num, nullptr));
        }
        size ++;
    }

    void remove(Val num){
        Node<Val> * before;
        Node<Val> * after;
        Node<Val> *node = head;
        while (node->getNext() != nullptr && node->getNext()->getValue() != num){
            node = node->getNext();
        }
        if (!node->getNext()){
            throw "have no more element";
        }
        before = node;
        node = node->getNext();
        after = node->getNext();

        delete node;
        before->setNext(after);

        size --;
    }

    friend ostream& operator << (ostream& out , LinkedList& linkedList){
        Node<Val> * print = linkedList.head;
        while (print){
            out << print->getValue()<< " ";
            print = print->getNext();
        }
        return out;
    }

    Val &operator [](int index){
        if(index < 0 || index > size){
            throw "Out of bound exception \n";
        }
        Node<Val> * toReturn = head;
        for(int i = 0; i < index; i++){
            toReturn = toReturn->getNext();
        }
        return toReturn->getValue();
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
