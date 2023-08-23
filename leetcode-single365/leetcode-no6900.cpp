#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(),diff = set(nums.begin(), nums.end()).size();
        int ans = 0;
        vector<unordered_map<int,int>> lastTimes;
        unordered_map<int,int> curData;
        for (int i = 0;i < n;i++){
            for (int j = i;j <n;j++){
                if (i == 0){
                    curData[nums[j]] ++;
                    if (curData.size() >= diff){
                        ans ++;
                    }
                    lastTimes.push_back(curData);
                } else {
                    lastTimes[j][nums[i-1]]--;
                    if (lastTimes[j][nums[i-1]] == 0){
                        lastTimes[j].erase(nums[i-1]);
                    }
                    if (lastTimes[j].size() >= diff){
                        ans ++;
                    }
                }
            }
//            for (auto [x,y] : lastTimes[i]){
//                cout << x << " " << y << endl;
//            }
//            cout << string(10,'-') << endl;
        }
        return ans;
    }
};

class Solution2 {
public:
    int countCompleteSubarrays(vector<int> &nums) {
        int n = nums.size(), diff = set(nums.begin(), nums.end()).size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> curData;
            for (int j = i; j < n; j++) {
                curData[nums[j]]++;
                if (curData.size() >= diff) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,3,1,2,2};
    cout << test.countCompleteSubarrays(eg1) << endl;
    vector<int> eg2 = {5,5,5,5};
    cout << test.countCompleteSubarrays(eg2) << endl;
}
//
// Created by ASUS on 2023/7/30.
//
