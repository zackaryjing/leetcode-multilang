#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        //set<int> judge(nums.begin(), nums.end());
        //if (judge.size() == 1) return true;
        if ((nums[0] - nums[n-1]) > 0){
            for (int i = 1;i < n;i++){
                if (nums[i] > nums[i-1]) return false;
            }
        } else if ((nums[0] - nums[n-1]) < 0){
            for (int i = 1;i<n;i++){
                if (nums[i] < nums[i-1]) return false;
            }
        } else {
            for (int i = 1;i<n;i++){
                if (nums[i] != nums[0]) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,2,3};
    cout << test.isMonotonic(eg1) << endl;
    vector<int> eg2 = {6,5,4,4};
    cout << test.isMonotonic(eg2) << endl;
    vector<int> eg3 = {6,5,4,8};
    cout << test.isMonotonic(eg3) << endl;
    vector<int> eg4 = {5,5,5,5};
    cout << test.isMonotonic(eg4) << endl;
}
//
// Created by ASUS on 2023/7/22.
//
