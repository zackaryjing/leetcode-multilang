#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <minmax.h>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int length = min(nums1.size(),nums2.size());
        cout << length << endl;
        for (int i = nums2.size() - 1;i >= 0 ;i++){
            for (int j = 0;j < min(nums2.size(),length);j++){
            };

        }
    }
};

int main(){
    Solution test;
    test.findLength();
}
//
// Created by ASUS on 2023/6/20.
//
