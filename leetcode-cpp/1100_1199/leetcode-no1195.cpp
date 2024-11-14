#include <iostream>
#include <vector>
#include <functional>
//#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;


class FizzBuzz {
private:
    int volatile cur = 1;
    int n;
    mutex mut;
    condition_variable cv;

public:
    FizzBuzz(int n) : n(n) ,mut(),cv() {
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (cur <= n) {
            unique_lock<mutex> lock(mut);
            if (cur % 3 == 0 and cur % 15 != 0) {
                printFizz();
                cur++;
                cv.notify_all();
            } else {
                cv.wait(lock);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (cur <= n) {
            unique_lock<mutex> lock(mut);
            if (cur % 5 == 0 and cur % 15 != 0) {
                printBuzz();
                cur++;
                cv.notify_all();
            } else {
                cv.wait(lock);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (cur <= n) {
            unique_lock<mutex> lock(mut);
            if (cur % 15 == 0) {
                printFizzBuzz();
                cur++;
                cv.notify_all();
            } else {
                cv.wait(lock);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (cur <= n) {
            unique_lock<mutex> lock(mut);
            if (cur % 5 != 0 and cur % 3 != 0) {
                printNumber(cur);
                cur++;
                cv.notify_all();
            } else {
                cv.wait(lock);
            }
        }
    }
};

void printFizz() {
    cout << "fizz ";
}

void printBuzz() {
    cout << "buzz ";
}

void printFizzBuzz() {
    cout << "fizzbuzz ";
}

void printNumber(int a) {
    cout << a << " ";
}


int main() {
    FizzBuzz test(20);
    thread t1(&FizzBuzz::fizz,&test,printFizz);
    thread t2(&FizzBuzz::buzz,&test,printBuzz);
    thread t3(&FizzBuzz::fizzbuzz,&test, printFizzBuzz);
    thread t4(&FizzBuzz::number,&test, printNumber);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
//
// Created by ASUS on 2024/9/4.
//
