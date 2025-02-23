#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size();
        int i = 0;
        for (; i < n - 1; ++i) {
            if (bits[i] == 1) {
                i++;
            };
        }
        if (i == n) {
            return false;
        } else {
            return true;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isOneBitCharacter(*make_unique<vector<int> >(vector{1, 0, 0})) << endl; // true
    cout << test.isOneBitCharacter(*make_unique<vector<int> >(vector{1, 1, 1, 0})) << endl; // false
    cout << test.isOneBitCharacter(*make_unique<vector<int> >(vector{0, 1, 1, 0})) << endl; // true
}

//
// 10101111x  << true
// 100101110x << false
// 100101110


//
// Created by ASUS on 2025/2/19.
//
