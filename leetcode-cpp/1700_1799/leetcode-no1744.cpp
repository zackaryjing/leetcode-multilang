// problem: https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

#include "../utils/vector_helper.h"
using namespace std;

// namespace std {
//     template<>
//     struct iterator_traits<vector<int>::iterator> {
//         using value_type = uint64_t;
//     };
// }

namespace std {
    template<>
    struct iterator_traits<std::vector<int>::iterator> {
        using difference_type = std::ptrdiff_t;
        using value_type = uint64_t;
        using pointer = uint64_t *;
        using reference = uint64_t &;
        using iterator_category = std::random_access_iterator_tag;
    };
}


class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        int m = candiesCount.size();
        vector<uint64_t> prefix(m, 0LL);
        partial_sum(candiesCount.begin(), candiesCount.end(), prefix.begin(), std::plus<uint64_t>());
        int n = queries.size();
        vector<bool> res;
        res.reserve(n);
        for (auto query: queries) {
            uint64_t type = query[0];
            uint64_t day = query[1];
            uint64_t max_cnt = query[2];
            uint64_t low = day + 1;
            uint64_t high = (day + 1) * max_cnt;
            res.push_back(prefix[type] >= low and (type > 0 ? prefix[type - 1] : 0) + 1 <= high);
        }
        return res;
    }
};


// Time spent 2:29:42
// 对于一个中等来说，这是难以置信的时间。现在是凌晨2:12，永远永远，不要过于相信AI。
// chatgpt给出的 partial_sum 的用法，让我花了两个小时去查找bug.
// 简而言之，partial_sum 计算会发生严重的溢出。
class Solution2 {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        int m = candiesCount.size();

        vector<uint64_t> prefix(m, 0LL);
        // partial_sum(candiesCount.begin(), candiesCount.end(), prefix.begin(), std::plus<uint64_t>());
        prefix[0] = static_cast<uint64_t>(candiesCount[0]);
        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + static_cast<uint64_t>(candiesCount[i]);
        }

        int n = queries.size();
        vector<bool> res;
        res.reserve(n);
        int i = 0;
        for (auto query: queries) {
            i++;
            uint64_t low = static_cast<uint64_t>(query[1]) + 1;
            uint64_t high = static_cast<uint64_t>(query[2]) * (static_cast<uint64_t>(query[1]) + 1LL);
            auto first = ranges::partition_point(prefix, [low](uint64_t x) { return x < low; });
            auto second = ranges::partition_point(prefix, [high](uint64_t x) { return x < high; });
            int type = query[0];
            int l = first - prefix.begin();
            int h = second - prefix.begin();
            if (second == prefix.end()) {
                h = static_cast<int>(prefix.size());
            }
            if (l <= +type && type <= h) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.canEat(temp_vector<int>({9}),
                            temp_vector<vector<int>>({{1, 4, 1}})));
    show_vector(test.canEat(temp_vector<int>({7, 4, 5, 3, 8}),
                            temp_vector<vector<int>>({{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}})));
    show_vector(test.canEat(temp_vector<int>({5, 2, 6, 4, 1}),
                            temp_vector<vector<int>>({{3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}})));
}

//
// Created By Zackary At 2025-05-28 23:19:13
//
