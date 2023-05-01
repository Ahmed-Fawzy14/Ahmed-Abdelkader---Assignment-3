#pragma once
template <typename T>
class Queue {
private:
    T q[100];
    int front;
    int rear;

public:
    Queue();

    bool isEmpty();

    bool isFull();


    void push(T x);

    void pop();

    void printQueue();
};
