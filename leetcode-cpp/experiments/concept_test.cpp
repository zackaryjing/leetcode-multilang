#include <concepts>
#include <iostream>

using namespace std;

template<typename T>
    requires requires(T t)
    {
        t + t;
    }
T add(T a, T b) {
    return a + b;
}

template<typename bulabula>
    requires (sizeof(bulabula) >= 8)
bulabula big_add(bulabula a, bulabula b) {
    return a + b;
}


int main() {
    cout << add(10, 10) << endl;;
    cout << big_add(10.0, 10.0) << endl;
}

