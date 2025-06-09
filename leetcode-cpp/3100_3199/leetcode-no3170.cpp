// problem: https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/?envType=daily-question&envId=2025-06-07
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <set>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// time spent: 1:46:32

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        auto chCnt = vector(26, stack<int>());
        for (int i = 0; i < n; ++i) {
            if (auto ch = s[i]; ch == '*') {
                for (auto &st: chCnt) {
                    if (not st.empty()) {
                        s[st.top()] = '*';
                        st.pop();
                        break;
                    }
                }
            } else {
                chCnt[ch - 'a'].push(i);
            }
        }
        s.erase(ranges::remove(s, '*').begin(), s.end());
        return s;
    }
};


class Solution2 {
public:
    string clearStars(string s) {
        string res;
        const int n = static_cast<int>(s.size());
        res.reserve(n);
        using P = pair<char, int>;
        auto cmp = [](const P &a, const P &b)-> bool {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a < b;
        };
        priority_queue<P, vector<P>, decltype(cmp)> toRm(cmp);
        int rmQueueSize = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (auto ch = s[i]; ch == '*') {
                rmQueueSize += 1;
            } else {
                if (rmQueueSize) {
                    if (toRm.size() < rmQueueSize) {
                        toRm.emplace(ch, i);
                    } else {
                        if (ch < toRm.top().first) {
                            toRm.pop();
                            toRm.emplace(ch, i);
                        }
                    }
                }
            }
        }
        auto &data = []<typename T0>(T0 &pq)-> auto & {
            struct Temp : T0 {
                static auto & access(Temp &pq_) {
                    return pq_.c;
                }
            };
            return Temp::access(static_cast<Temp &>(pq));
        }(toRm);
        auto view = data | views::transform([](auto &data) { return data.second; });
        unordered_set rmSet(view.begin(), view.end());

        // while (not toRm.empty()) {
        //     rmSet.insert(toRm.top().second);
        //     toRm.pop();
        // }
        for (int i = 0; i < n; i++) {
            if (const auto ch = s[i]; ch != '*' and not rmSet.contains(i)) {
                res.push_back(ch);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.clearStars("aaba*") << endl;
    cout << test.clearStars("abc") << endl;
    cout << test.clearStars("***") << endl;
    cout << test.clearStars("ydk*ykk*") << endl;
}

//
// Created By Zackary At 2025-06-07 16:06:07
//
