#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class MyStack {
    deque<int> _data;

public:
    MyStack() {
    }

    void push(int x) {
        _data.push_back(x);
    }

    int pop() {
        int n = _data.size();
        int i = 0;
        while (i < n - 1) {
            _data.push_back(_data.front());
            _data.pop_front();
            i++;
        }
        auto temp = _data.front();
        _data.pop_front();
        return temp;
    }

    int top() {
        int n = _data.size();
        int i = 0;
        while (i < n - 1) {
            _data.push_back(_data.front());
            _data.pop_front();
            i++;
        }
        auto temp = _data.front();
        _data.push_back(_data.front());
        _data.pop_front();
        return temp;
    }

    bool empty() {
        return _data.empty();
    }
};


int main() {
    MyStack test;
    test.push(3);
    test.push(4);
    test.push(6);
    test.push(8);
    test.push(10);
    test.pop();
    test.pop();
    cout << test.top() << endl; // 6
    test.pop();
    cout << test.top() << endl; // 4
    test.pop();
    test.pop();
    cout << test.empty() << endl; // true / 1
}


//
// Created by ASUS on 2025/2/8.
//
