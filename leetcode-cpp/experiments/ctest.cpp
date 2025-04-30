#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class Test {
    int a = 10;
public:
    void show() {
        cout << a << endl;
    }
}

int main() {
    Test test;
    &Test::show;
//    thread t1(&Test::show, test);
}


//
// Created by ASUS on 2023/8/11.
//
