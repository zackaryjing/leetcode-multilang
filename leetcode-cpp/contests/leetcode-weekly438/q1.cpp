#include <iostream>
#include <vector>

#include "../../utils/vector_helper.h"

using namespace std;


class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        if (n == 2) {
            return s[0] == s[1];
        }
        vector<int> nums;
        for (auto k: s) {
            nums.push_back(k - '0');
        }

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                nums[j] = (nums[j + 1] + nums[j]) % 10;
            }
            // show_vector(nums);
        }
        return nums[0] == nums[1];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.hasSameDigits("3902") << " <-" << endl;
    cout << test.hasSameDigits("34789") << " <-" << endl;
    cout << test.hasSameDigits("347891") << " <-" << endl;
    cout << test.hasSameDigits("3478999") << " <-" << endl;
    cout << test.hasSameDigits("327891") << " <-" << endl;
    cout << test.hasSameDigits("3678999") << " <-" << endl;
    cout << test.hasSameDigits("3678599") << " <-" << endl;
    cout << test.hasSameDigits("3678599") << " <-" << endl;
    cout << test.hasSameDigits("3278599") << " <-" << endl;
}


//
// Created by ASUS on 2025/2/23.
//
