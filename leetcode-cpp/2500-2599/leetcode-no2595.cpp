#include <bitset>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<32> num(n);
        int ones = num.count();
        int ones_even = 0;
        for (int i = 0; i < 32; i += 2) {
            ones_even += ((n >> i) & 0x1) == 0x1;
        }
        return {ones_even, ones - ones_even};
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.evenOddBit(50));
}


//
// Created by ASUS on 2025/2/20.
//
