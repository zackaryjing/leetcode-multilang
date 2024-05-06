#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for (int i = n - 1;i >= 0;i--){
            dp[i][i] = 1;
            for (int j = i + 1;j < n;j++){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i][j-1];
                } else {
                    int tmp = INT_MAX;
                    for (int k = i;k < j;k++){
                        tmp = min(tmp,dp[i][k] + dp[k+1][j]);
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main(){
    Solution test;
    cout << test.strangePrinter("aaabbb") << endl;
    cout << test.strangePrinter("aba") << endl;
}
//
// Created by ASUS on 2023/7/15.
//
