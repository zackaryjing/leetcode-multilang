// problem: https://leetcode.cn/problems/car-fleet/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution2 {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = position.size();
        auto ps = views::zip(position, speed);
        ranges::sort(ps);
        vector<float> arriveTime(n);
        for (int i = n - 1; i >= 0; --i) {
            arriveTime[i] = static_cast<float>(target - get<0>(ps[i])) / static_cast<float>(get<1>(ps[i]));
        }
        float lastTime = arriveTime[n - 1];
        int troopCnt = n;
        for (int i = n - 2; i >= 0; --i) {
            if (arriveTime[i] <= lastTime) {
                troopCnt--;
            } else {
                lastTime = arriveTime[i];
            }
        }
        return troopCnt;
    }
};


#include <ranges>
class Solution3 {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        const int n = position.size();
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; ++i) {
            ps.emplace_back(position[i], speed[i]);
        }
        ranges::sort(ps);
        vector<float> arriveTime(n);
        for (int i = n - 1; i >= 0; --i) {
            arriveTime[i] = static_cast<float>(target - ps[i].first) / static_cast<float>(ps[i].second);
        }
        float lastTime = arriveTime[n - 1];
        int troopCnt = n;
        for (int i = n - 2; i >= 0; --i) {
            if (arriveTime[i] <= lastTime) {
                troopCnt--;
            } else {
                lastTime = arriveTime[i];
            }
        }
        return troopCnt;
    }
};

#include <execution>
#include <ranges>
#define MASK 0xfffff
class Solution {
public:
    // best ver. but mutlicore are not supported on leetcode.
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        const size_t n = position.size();
        vector<long long> ps;
        for (int i = 0; i < n; ++i) {
            ps.emplace_back((static_cast<long long>(position[i]) << 20) + speed[i]);
        }
        sort(std::execution::par_unseq, ps.begin(), ps.end());
        float arriveTime = 0.0;
        float lastTime = static_cast<float>(target - (ps[n - 1] >> 20)) / static_cast<float>(ps[n - 1] & MASK);
        int troopCnt = n;
        for (int i = n - 2; i >= 0; --i) {
            arriveTime = static_cast<float>(target - (ps[i] >> 20)) / static_cast<float>(ps[i] & MASK);
            if (arriveTime <= lastTime) {
                troopCnt--;
            } else {
                lastTime = arriveTime;
            }
        }
        return troopCnt;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.carFleet(12, temp_vector({10, 8, 0, 5, 3}), temp_vector({2, 4, 1, 1, 3})) << endl;
    cout << test.carFleet(10, temp_vector({0, 4, 2}), temp_vector({2, 1, 3})) << endl;
}

//
// Created By jing At 2025-10-25 20:18
//
