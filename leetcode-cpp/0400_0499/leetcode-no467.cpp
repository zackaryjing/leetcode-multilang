#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int k = 1;
        vector<int> dp = vector<int>(26, 0);
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) {
                if ((s[i] - s[i - 1] + 26) % 26 == 1) {
                    ++k;
                    // cout << "there" << endl;
                } else {
                    k = 1;
                }
            }
            // cout << "here " << s[i] << " " <<  dp[s[i]] << ", " << k << endl;
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }
        // for (auto k : dp) {
        //     cout << k << endl;
        // }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    Solution test;
    cout << test.findSubstringInWraproundString("a") << endl;;
    cout << test.findSubstringInWraproundString("cac") << endl;;
    cout << test.findSubstringInWraproundString("zab") << endl;;
}


//
// Created by ASUS on 2025/2/6.
//
