// problem: https://leetcode.cn/problems/longest-well-performing-interval/
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int longestWPI(vector<int> &hours) {
        vector<int> st = {0};
        int n = hours.size();
        vector<int> sm(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sm[i] = (hours[i - 1] > 8 ? 1 : -1) + sm[i - 1];
            if (sm[i] < sm[st.back()]) {
                st.push_back(i);
            }
        }
        int ans = 0;
        for (int j = n; j >= 0; --j) {
            while (not st.empty() and sm[j] > sm[st.back()]) {
                ans = max(ans, j - st.back());
                st.pop_back();
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.longestWPI(temp_vector<int>({9, 9, 6, 0, 6, 6, 9})) << endl;
    cout << test.longestWPI(temp_vector<int>({6, 6, 9})) << endl;
}

//
// Created By Zackary At 2025-04-24 16:41:03
//
