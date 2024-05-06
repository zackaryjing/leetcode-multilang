#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int pre = 1,max = 1;
        for (int i = 1;i<n;i++){
            if (nums[i] > nums[i-1]) {
                pre += 1;
                max = (pre > max) ? pre : max;
            } else {
                pre = 1;
            }
        }
        return max;
    }
};

int main(){
    Solution test;
    vector<int> exp = {1,3,5,4,7};
    cout << test.findLengthOfLCIS(exp) << endl;
}
//public:
//    int findLengthOfLCIS(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> data;
//        data[0] = 1;
//        for (int i = 1;i<n;i++){
//            if (nums[i] > nums[i-1]){
//                data[i] = data[i-1];
//            } else {
//                for (int j = i;j>=0;j--){
//                    if (nums[i] > nums[j]) {
//                        data[i] = data[j] + 1;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//};
//
// Created by ASUS on 2023/6/28.
//
