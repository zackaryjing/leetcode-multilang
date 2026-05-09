// problem: https://leetcode.cn/problems/hand-of-straights/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> cnt;
        for (auto num: hand) {
            cnt[num]++;
        }
        int times = hand.size() / groupSize;
        for (int i = 0; i < times; ++i) {
            int start = cnt.begin()->first;
            for (int j = 0; j < groupSize; ++j) {
                auto cur = start + j;
                if (cnt.contains(cur)) {
                    if (--cnt[cur] == 0) {
                        cnt.erase(cur);
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ranges::sort(hand);
        int n = hand.size();
        for (auto num: hand) {
            if (not pq.empty() and num == pq.top())
                pq.pop();
            else
                for (int i = 1; i < groupSize; ++i) pq.push(num + i);
            if (pq.size() >= n) return false;
        }
        return pq.empty();
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.isNStraightHand(temp_vector({1, 2, 3, 6, 2, 3, 4, 7, 8}), 3) << endl;
}

//
// Created By jing At 2025-10-26 16:40
//
