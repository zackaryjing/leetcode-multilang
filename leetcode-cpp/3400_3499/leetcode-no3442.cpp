// problem: https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26);
        for (const auto &ch: s) {
            cnt[ch - 'a']++;
        }
        int maxOddNum = 0;
        int minEvenNum = INT_MAX;
        for (auto num: cnt) {
            if (num & 1) {
                maxOddNum = max(maxOddNum, num);
            } else if (num > 0){
                minEvenNum = min(minEvenNum, num);
            }
        }
        // cout << maxOddNum << ", " << minEvenNum << endl;
        return maxOddNum - minEvenNum;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDifference("aaaaabbc") << endl;
    cout << test.maxDifference("abcabcab") << endl;
}

//
// Created By Zackary At 2025-06-10 13:16:43
//
