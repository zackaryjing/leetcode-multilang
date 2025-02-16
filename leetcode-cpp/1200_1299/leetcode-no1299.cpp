#include <iostream>
#include "../utils/vector_helper.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int max_num = -1;
        for (vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); ++it) {
            int origin_val = *it;
            *it = max_num;
            max_num = max(max_num, origin_val);
        }
        return arr;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {17, 18, 5, 4, 6, 1};
    auto res1 = test.replaceElements(eg1);
    show_vector(res1);
}

//
// Created by ASUS on 2025/2/16.
//
