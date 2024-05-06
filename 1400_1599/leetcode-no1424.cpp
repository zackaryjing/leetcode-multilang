#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> data;
        vector<int> ans;
        for (int i = 0 ;i < nums.size();i++){
            for (int j = 0;j < nums[i].size();j++){
                data[i + j].push_back(nums[i][j]);
            }
        }
        for (int i = 0; i < data.size(); ++i) {
            ans.insert(ans.end(),data[i].rbegin(),data[i].rend());
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = test.findDiagonalOrder(eg1);
    for (auto j : res) cout << j << " ";
    cout << endl;
    vector<vector<int>> eg2 = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    vector<int> res2 = test.findDiagonalOrder(eg2);
    for (auto j : res2) cout << j << " ";
}
//
// Created by ASUS on 2023/7/27.
//
