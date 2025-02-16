#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        map<int, int> jumps; // 跳转次数到下标
        jumps[0] = 0;
        int ans;
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (auto [cnts,index]: jumps) {
                if (index >= i) {
                    ans = cnts;
                    jumps[cnts + 1] = max(jumps[cnts + 1], i + nums[i]);
                    if (jumps[cnts + 1] >= n - 1) {
                        return cnts + 1;
                    }
                    break;
                } else {
                    jumps.erase(cnts);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {2, 3, 1, 1, 4};
    cout << test.jump(eg1) << endl;;
    vector<int> eg2 = {0};
    cout << test.jump(eg2) << endl;;
}


//
// Created by ASUS on 2025/2/12.
//
