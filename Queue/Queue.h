#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

// first in first out

#include <iostream>
using namespace std;

template <typename Val>
class Queue {
private:
    Val* queue;
    int size;
    int counter;
    int head;
    int tail;

    void increaseQueue(){
        Val *newQueue = new Val [size + 10];
        for (int i = head; i < tail ; i++) {
            newQueue[i] = queue[i];
        }
        delete[](queue);
        queue = newQueue;
        size += 10;
    }

public:
        Queue(int sizeQueue) {
        size = sizeQueue;
        counter = 0;
        head = 0;
        tail = 0;
        queue = new Val[size];
    }

    Queue(const Queue &otherQueue) : queue(new Val[size]), size(otherQueue.size), counter(otherQueue.counter),
                                                                   head(otherQueue.head), tail(otherQueue.tail) {
        for (int i = 0; i < size; i++){
            queue[i] = otherQueue.queue[i];
        }
    }

    bool isEmpty(){
        return counter == 0;
    }

    void push(Val value){
        if(tail == size){
            increaseQueue();
        }

        queue[tail ++] = value;
        counter ++;
    }

    Val pop(){
        if(!isEmpty()){
            Val toReturn = queue[head ++];
            counter --;
            return  toReturn;
        }
    }

    Val print(){

        if (isEmpty()){
            cout << "The queue is empty";
            return Val();
        }

        for (int i = tail-1; i >= head; i--){
            cout << queue[i] << endl;
        }
    }


};


#endif //QUEUE_QUEUE_H
