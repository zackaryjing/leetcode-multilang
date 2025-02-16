#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../utils/vector_helper.h"

using namespace std;

class SummaryRanges_mine {
    // 过了但是很一般，抄下官解
public:
    // TODO: 总结一下，我应该使用map而非vector，map可以自动排序。编码过程上来说，几种情况应该区分的更清晰一些。
    vector<pair<int, int> > data;
    bool is_empty = true;

    SummaryRanges_mine() {
    }

    void addNum(int value) {
        if (is_empty) {
            data.emplace_back(value, value);
            is_empty = false;
        }
        auto pos = lower_bound(data.begin(), data.end(), value, [](const pair<int, int> &a, const int &b) {
            return a.first < b;
        });
        if (pos == data.end()) {
            if (value > data.back().second + 1) {
                data.insert(pos, make_pair(value, value));
            } else if (value == data.back().second + 1) {
                (pos - 1)->second = value;
            }
            return;
        }

        if (value == pos->first) {
            return;
        }
        if (pos->first == value + 1) {
            if (pos != data.begin() and (pos - 1)->second == value - 1) {
                pos->first = (pos - 1)->first;
                data.erase(pos - 1);
            } else {
                pos->first = value;
            }
        } else {
            if (pos != data.begin() and (pos - 1)->second >= value - 1) {
                if ((pos - 1)->second == value - 1) {
                    (pos - 1)->second = value;
                }
            } else {
                data.insert(pos, make_pair(value, value));
            }
        }
    }

    vector<vector<int> > getIntervals() {
        vector<vector<int> > ans;
        ans.reserve(data.size());
        for (auto vals: data) {
            cout << "f: " << vals.first << " s: " << vals.second << endl;
            ans.push_back({vals.first, vals.second});
        }
        cout << endl;
        return ans;
    }
};

class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {
    }

    void addNum(int val) {
        auto interval1 = intervals.upper_bound(val);
        auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));
        if (interval0 != intervals.end() and interval0->first <= val and val <= interval0->second) {
            return;
        } else {
            bool left_side = (interval0 != intervals.end() and interval0->second + 1 == val);
            bool right_side = (interval1 != intervals.end() and interval1->first - 1 == val);

            if (left_side and right_side) {
                int left = interval0->first, right = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(left, right);
            } else if (left_side) {
                ++interval0->second = val;
            } else if (right_side) {
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            } else {
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int> > getIntervals() {
        vector<vector<int> > ans;
        for (const auto &[left, right]: intervals) {
            ans.push_back({left, right});
        }
        return ans;
    }
};


int main(int argc, char *argv[]) {
    SummaryRanges_mine test;
    test.addNum(1);
    auto ans = test.getIntervals();
    test.addNum(1);
    ans = test.getIntervals();
    // test.addNum(7);
    // ans = test.getIntervals();
    // test.addNum(2);
    // ans = test.getIntervals();
    // test.addNum(3);
    // ans = test.getIntervals();
    // test.addNum(2);
    // ans = test.getIntervals();
    // test.addNum(0);
    // ans = test.getIntervals();
    // test.addNum(5);
    // ans = test.getIntervals();
    // test.addNum(6);
    // ans = test.getIntervals();
    // test.addNum(4);
    // ans = test.getIntervals();
}


//
// Created by ASUS on 2025/2/10.
//
