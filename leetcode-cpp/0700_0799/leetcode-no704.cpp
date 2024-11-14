#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1;
        while (left != right){
            int mid = (left + right + 1) / 2;
            if (nums[mid] == target){
                left = mid;
                break;
            } else if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        if (nums[left] == target){
            return left;
        } else {
            return -1;
        }
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {-1,0,3,5,9,12};
    cout << test.search(eg1,9) << endl;

}
//
// Created by ASUS on 2023/7/18.
//
