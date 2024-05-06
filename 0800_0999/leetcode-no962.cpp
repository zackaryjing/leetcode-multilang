#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> tmp;
        for (int i = 0;i < n;i++){
            tmp.push_back({nums[i],i});
        }
        sort(tmp.begin(), tmp.end());
        int minpos = n,ans;
        for (auto j : tmp){
            minpos = min(minpos,j[1]);
            ans = max(j[1] - minpos,ans);
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {6,0,8,2,1,5};
    cout << test.maxWidthRamp(eg1) << endl;
    vector<int> eg2 = {9,8,1,0,1,9,4,0,4,1};
    cout << test.maxWidthRamp(eg2) << endl;
}
//
// Created by ASUS on 2023/7/19.
//