#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int k = ~n;
        int times = 0;
        while (k < 0) {
            k <<= 1;
            times++;
        }
        k >>= times;
        return k;
    }
};

int main() {
    Solution test;
    cout << test.bitwiseComplement(5) << endl;;
    cout << test.bitwiseComplement(7) << endl;;
}

//
// Created by ASUS on 2025/2/2.
//
