#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n % 2 == 1) {
            n /= 2;
        }
        while (n > 0) {
            // cout << n << ',' << endl;
            if (n % 2) {
                return false;
            }
            n = n / 2;
            if (n % 2 != 1) {
                return false;
            }
            n = n / 2;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.hasAlternatingBits(8) << endl;
    cout << test.hasAlternatingBits(10) << endl;
    cout << test.hasAlternatingBits(0) << endl;
    cout << test.hasAlternatingBits(1) << endl;
    cout << test.hasAlternatingBits(3) << endl;
    cout << test.hasAlternatingBits(5) << endl;
    cout << test.hasAlternatingBits(7) << endl;
}


//
// Created by ASUS on 2025/2/18.
//
