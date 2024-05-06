#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        if (nums[right] > nums[left]){
            return nums[left];
        }
        int mid = 0;
        while (left != right){
            mid = (left + right + 1) / 2;
            if (nums[mid] < nums[left]){
                right = mid - 1;
            } else if (nums[mid] > nums[left]){
                left = mid;
            }
        }
        return min(nums[mid],nums[(mid + 1) % nums.size()]);
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {3,4,5,1,2};
    cout << test.findMin(eg1) << endl;
    vector<int> eg2 = {4,5,6,7,0,1,2};
    cout << test.findMin(eg2) << endl;
    vector<int> eg3 = {4,5,1,2,3};
    cout << test.findMin(eg3) << endl;
    vector<int> eg4 = {1};
    cout << test.findMin(eg4) << endl;
}
//
// Created by ASUS on 2023/8/10.
//
