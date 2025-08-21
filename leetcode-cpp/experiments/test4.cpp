#include <iostream>
#include <functional>

using namespace std;

void func(function<void()> fun) {
    for (int i = 0;i < 30;++i) {
        fun();
    }
}


int main() {
    int a = 10;
    cout << a << endl;

    auto add_one = [&a]() {
        a++;
    };


    func(add_one);
    cout << a << endl;

    auto times_two = [a]() {
        int b = a;
        b *= 2;
    };

    func(times_two);
    cout << a << endl;
}