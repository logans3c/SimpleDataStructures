#include <iostream>

template<class T>
class CircularQueue {
private:
    int front, rear, capacity;
    T* array ;

public:
    CircularQueue(int size) : capacity(size), front(-1), rear(-1) {
        array = new T[capacity];
    }

    ~CircularQueue() {
        delete[] array;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(T item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity; // circular increment
        }

        array[rear] = item;
        std::cout << item << " enqueued to the queue." << std::endl;
    }

    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            throw std::runtime_error("Queue is empty");
        }

        T item = array[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        std::cout << item << " dequeued from the queue." << std::endl;
        return item;
    }

    T peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            throw std::runtime_error("Queue is empty");
        }

        return array[front];
    }
};

int main() {
    CircularQueue<int> cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    std::cout << "Front element: " << cq.peek() << std::endl;

    cq.dequeue();

    cq.enqueue(4);
    cq.enqueue(5);

    while (!cq.isEmpty()) {
        cq.dequeue();
    }

    return 0;
}//
// Created by moham on 11/23/2023.
//
