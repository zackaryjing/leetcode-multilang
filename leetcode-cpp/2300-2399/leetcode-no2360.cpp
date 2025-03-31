// problem: https://leetcode.cn/problems/longest-cycle-in-a-graph/description/?envType=daily-question&envId=2025-03-29
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> label(n);
        int cur_label = 0;
        int ans = -1;
        for (int i = 0;i < n;i++) {
            if (label[i]) {
                continue;
            }
            int pos = i;
            int start_label = cur_label;
            while (pos >= 0) {
                ++cur_label;
                if (label[pos]) {
                    if (label[pos] > start_label) {
                        ans = max(ans,cur_label - label[pos]);
                    }
                    break;
                }
                label[pos] = cur_label;
                pos = edges[pos];
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
}

//
// Created by ASUS on 2025/3/29.
//
