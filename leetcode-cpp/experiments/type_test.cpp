#include <iostream>
#include <vector>
#include <cxxabi.h>
#include <typeinfo>
#include <cstdlib>

using namespace std;

using good = double;

void foo(int h) {
    typedef good bad;
    cout << (bad) h / 3 << endl;
}

template<typename T>
void bar(int h) {
    typedef typename T::value_type a;
    cout << typeid(a).name() << endl;
    cout << abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr) << endl;
}


template<auto guesswhatiam>
struct Test {
    void call() {
        guesswhatiam();
    }
};

int main() {
    bar<vector<Test<foo>>>(10);
}
