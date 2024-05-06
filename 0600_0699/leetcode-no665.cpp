#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        int valid = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (i + 2 <= n - 1) {
                    if (nums[i] <= nums[i + 2]) {
                        valid--;
                        continue;
                    }
                } else if (i + 2 == n) {
                    valid--;
                    continue;
                }
                if (0 <= i - 1) {
                    if (nums[i - 1] <= nums[i + 1]) {
                        valid--;
                        continue;
                    }
                } else if (i == 0) {
                    valid--;
                    continue;
                }
                if (valid == 1 or valid <= 0) {
                    return false;
                }
            }
        }
        if (valid < 0) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution test;
    vector<int> num1 = {4,2,3};
    vector<int> num2 = {4,2,1};
    cout << test.checkPossibility(num1) << endl;
    cout << endl;
    cout << test.checkPossibility(num2) << endl;
    cout << endl;
    vector<int> num3 = {3,4,2,3};
    cout << test.checkPossibility(num3) << endl;
    cout << endl;
    vector<int> num4 = {1,5,4,6,7,10,10,8,9};
    cout << test.checkPossibility(num4) << endl;
    cout << endl;
}
//
// Created by ASUS on 2024/3/29.
//
