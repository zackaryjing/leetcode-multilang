#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> past;
        int ans = 1;
        for (auto j : nums){
            int alone = 1;
            for (auto pairs : past){
                if (pairs.first == (j - 1)){
                    alone = 0;
                    past[j] = pairs.second++;
                    ans = max(ans,pairs.second);
                    past.erase(pairs.first);
                }
            }
            if (alone) past[j] = 1;
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> data(nums.begin(), nums.end());
        int ans = 1;
        for (auto j : data){
            int nxt = j + 1;
            int tmp = 1;
            if (data.find(j - 1) != data.end()) continue;
            while (data.find(nxt) != data.end()){
                nxt ++,tmp ++;
            }
            ans = max(ans,tmp);
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {100,4,200,1,3,2};
    cout << test.longestConsecutive(eg1) << endl;
}
//
// Created by ASUS on 2023/7/26.
//
