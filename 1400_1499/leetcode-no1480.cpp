#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(),nums.begin());
        return nums;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,3,4,5};
    vector<int> res = test.runningSum(eg1);
    for (auto j : res) {
        cout << j << endl;
    }

}
//
// Created by ASUS on 2023/7/24.
//
