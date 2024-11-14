#include "iostream"
#include "vector"
#include "unordered_set"
using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(int cur,int last,vector<int>& nums){
        if (cur == nums.size()){
            if (temp.size() >= 2){
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last){
            temp.push_back(nums[cur]);
            dfs(cur + 1,nums[cur],nums);
            temp.pop_back();
        }
        if (nums[cur] != last){
            dfs(cur + 1,last,nums);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0,INT_MIN,nums);
        return ans;
    }
};

int main(){
    Solution t;
    vector<int> a {4,6,7,7};
    for (auto each :t.findSubsequences(a)){
        for (auto tt : each){
            cout << tt << " ";
        }
        cout << "\n";
    };
}
//
// Created by ASUS on 2023/5/12.
//
