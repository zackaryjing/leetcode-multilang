#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long test = 2 * (long long)n;
        long long h = sqrt(test);
        if (h * (h + 1) > test) {
            return h - 1;
        } else {
            return h;
        }
    }
};

int main() {
    Solution test;
    cout << "asdf " << endl;
    cout << test.arrangeCoins(3) << endl;
    cout << test.arrangeCoins(4) << endl;
    cout << test.arrangeCoins(5) << endl;
    cout << test.arrangeCoins(6) << endl;
    cout << test.arrangeCoins(7) << endl;
    cout << test.arrangeCoins(8) << endl;

}
//
// Created by ASUS on 2024/3/28.
//
