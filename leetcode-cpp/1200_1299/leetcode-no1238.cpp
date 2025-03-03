#include <cmath>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int size = 1 << n;
        vector<int> data(size);

        int pos = 0;
        int times = 0;
        while (start > 0) {
            if (start & 0x1) {
                pos = (1 << times + 1) - 1 - pos;
            }
            start >>= 1;
            times++;
        }
        data[(0 - pos + size) % size] = 0;
        for (int i = 0; i < n; i++) {
            int temp_size = 1 << i;
            int delta = 1 << i;
            for (int j = temp_size; j < temp_size * 2; j++) {
                data[(j - pos + size) % size] = data[(2 * temp_size - 1 - j - pos + size) % size] + delta;
            }
        }
        return data;
    }
};


// 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 1 3 2 0 0 0 0 0 0 0 0 0 0 0 0
// 0 1 3 2 6 7 5 4 0 0 0 0 0 0 0 0
// 0 1 3 2 6 7 5 4 12 13 15 14 10 11 9 8


int main(int argc, char *argv[]) {
    Solution test;
    auto eg1 = test.circularPermutation(3, 2);
    show_vector(eg1);
}


//
// Created by ASUS on 2025/2/24.
//
