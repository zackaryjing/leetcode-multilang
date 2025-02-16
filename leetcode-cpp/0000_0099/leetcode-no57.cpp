#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Solution2 {
    // 能过，随便改的56题的代码，效率低
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > merged;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};


class Solution3 {
    // 官解
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int> > ans;
        for (const auto &interval: intervals) {
            if (interval[0] > right) {
                if (not placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (not placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};


class Solution {
    // 评论区里比较好的解法，非常优雅，值得学习
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
        auto beg = intervals.begin(), end = intervals.end();
        int &a = newInterval[0], &b = newInterval[1];
        auto l = lower_bound(beg, end, a, [](auto &a, int b) { return a[1] < b; });
        auto r = upper_bound(l, end, b, [](int b, auto &a) { return a[0] > b; });
        if (l != end) a = min(a, l[0][0]);
        if (r != beg) b = max(b, r[-1][1]);
        intervals.insert(intervals.erase(l, r), newInterval);
        return intervals;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {{1, 3}, {6, 9}};
    test.insert(eg1, *make_unique<vector<int> >(vector{2, 5}));
    vector<vector<int> > eg2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    test.insert(eg2, *make_unique<vector<int> >(vector{3, 8}));
}


//
// Created by ASUS on 2025/2/13.
//
