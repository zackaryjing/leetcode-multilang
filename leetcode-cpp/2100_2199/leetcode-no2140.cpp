// problem: https://leetcode.cn/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01
#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int> > &questions) {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; --i) {
            if (questions[i][1] + 1 + i < n) {
                dp[i] = max(dp[i + 1], dp[i + questions[i][1] + 1] + questions[i][0]);
            } else {
                dp[i] = max(dp[i + 1], static_cast<long long>(questions[i][0]));
            }
        }
        return dp[0];
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.mostPoints(*make_unique<vector<vector<int> > >(vector<vector<int> >({{3, 2}, {4, 3}, {4, 4}, {2, 5}})))
            << endl;
    cout << test.mostPoints(*make_unique<vector<vector<int> > >(vector<vector<int> >({
                {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}
            })))
            << endl;
}


//
// Created by ASUS on 2025/4/1.
//
