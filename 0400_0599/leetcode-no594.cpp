#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
    map<int, int> cnt;
public:
    int findLHS(vector<int> &nums) {
        for (auto i: nums) {
            cnt[i]++;
        }
        vector<pair<int,int>> temp;
        for (auto p : cnt) {
            temp.push_back(p);
        }
        int maxium = 0;
        for (int i = 1;i < temp.size();i++){
            if (temp[i].first - temp[i - 1].first == 1){
                maxium = max(maxium,temp[i].second + temp[i - 1].second);
            }
        }
        return maxium;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << test.findLHS(nums) << endl;
}
//
// Created by ASUS on 2024/2/21.
//
