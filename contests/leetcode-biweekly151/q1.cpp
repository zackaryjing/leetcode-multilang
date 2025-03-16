#include <iostream>
#include <vector>

#include "../../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int> &nums) {
        int odd_num = 0;
        int even_num = 0;
        for (auto k: nums) {
            if (k % 2) {
                odd_num++;
            } else {
                even_num++;
            }
        }
        vector<int> ans(even_num, 0);
        ans.insert(ans.end(), odd_num, 1); // 在 ans 的末尾添加 odd_num 个 1
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1({4, 3, 2, 1});
    show_vector(test.transformArray(eg1));
}


//
// Created by ASUS on 2025/3/1.
//
