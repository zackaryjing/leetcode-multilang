#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int last = 0;
        for (auto j : nums) {
            if (j == last){
                return {last,last + 1};
            }
            last = j;
        }
        return {};
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,2,4};
    vector<int> eg2 = {1,1};
    vector<int> ans = test.findErrorNums(eg1);
    for (auto i : ans) cout << i << endl;
}
//
// Created by ASUS on 2023/8/8.
//
