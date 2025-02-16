#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution2 {
    // 过了，但是有点低效
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
        map<int, int> data;
        for (auto piece: intervals) {
            auto first = piece[0], second = piece[1];
            data[first] = max(data[first], second);
        }
        pair<int, int> prev = *data.cbegin();
        auto it = data.cbegin();
        if (it != data.cend()) {
            ++it;
        }
        vector<vector<int> > ans;
        for (; it != data.cend(); ++it) {
            if (it->first <= prev.second) {
                prev.second = max(it->second, prev.second);
            } else {
                ans.push_back({prev.first, prev.second});
                prev = *it;
            }
        }
        ans.push_back({prev.first, prev.second});
        return ans;
    }
};


class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals) {
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

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}};
    test.merge(eg1);
    vector<vector<int> > eg2 = {{1, 4}, {4, 5}};
    test.merge(eg2);
}


//
// Created by ASUS on 2025/2/12.
//
