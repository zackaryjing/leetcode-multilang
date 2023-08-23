#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num1 = nums[0] * nums[1] * nums[nums.size()-1];
        int num2 = nums[nums.size()-3] * nums[nums.size()-2] * nums[nums.size()-1];
        return max(num1,num2);
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,3};
    vector<int> eg2 = {-1,-2,-3};
    vector<int> eg3 = {1,2,3,4};
    cout << test.maximumProduct(eg1) << endl;
    cout << test.maximumProduct(eg2) << endl;
    cout << test.maximumProduct(eg3) << endl;
}
//
// Created by ASUS on 2023/8/8.
//
