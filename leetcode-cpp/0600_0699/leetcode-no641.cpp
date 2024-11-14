#include <iostream>
#include <vector>

using namespace std;


class MyCircularDeque {
private:
    int *data;
    int front;
    int rear;
    int size;
public:
    MyCircularDeque(int k) {
        size = k + 1;
        data = new int[size];
        front = 0;
        rear = (front + 1) % size;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        } else {
            data[front] = value;
            if (front == 0) {
                front = size - 1;
            } else {
                front--;
            }
            return true;
        }
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        } else {
            data[rear] = value;
            if (rear == size - 1) {
                rear = 0;
            } else {
                rear++;
            }
            return true;
        }
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        } else {
            front = (front + 1) % size;
            return true;
        }
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        } else {
            rear = ((rear + size) - 1) % size;
            return true;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[(front + 1) % size];
        }
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[((rear + size) - 1) % size];
        }
    }

    bool isEmpty() {
        if (((front + 1) % size) == rear) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if (front == rear) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {

}
//
// Created by ASUS on 2024/8/9.
//
