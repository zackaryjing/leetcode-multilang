#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        int odd_pos = 1, even_pos = 0;
        for (auto j: nums) {
            if (j % 2 == 0) {
                ans[even_pos] = j;
                even_pos += 2;
            } else {
                ans[odd_pos] = j;
                odd_pos += 2;
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {4,2,5,7};
    vector<int> res = test.sortArrayByParityII(nums1);
    for (auto j : res){
        cout << j << " " ;
    }

}
//
// Created by ASUS on 2024/2/28.
//
