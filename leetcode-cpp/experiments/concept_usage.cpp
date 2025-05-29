#include <iostream>
using namespace std;

class CA {
public:
    int val;

    CA(int val) :
        val(val) {
    }

    CA operator+(CA &other) {
        return {this->val + other.val};
    }
};

class CB {
public:
    int val;

    CB(int val) :
        val(val) {
    }

    CB operator-(CB &other) {
        return {this->val - other.val};
    }
};

template<typename T>
    requires requires(T t)
    {
        t + t;
    }
T add(T a, T b) {
    return a + b;
}


template<typename T>
concept MinusConcept = requires(T t)
{
    t - t;
};


template<MinusConcept T>
T my_minus(T a, T b) {
    return a - b;
}

int main() {
    cout << add(CA(1), CA(2)).val << endl;
    cout << my_minus(CB(1), CB(2)).val << endl;
}
