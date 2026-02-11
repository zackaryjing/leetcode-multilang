// problem: https://leetcode.cn/problems/reveal-cards-in-increasing-order/?envType=problem-list-v2&envId=OOhHf3Bc
#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int n = deck.size();
        vector<int> prev(n), next(n), res(n);
        ranges::iota(prev, -1);
        ranges::iota(next, 1);
        ranges::sort(deck);
        next[n - 1] = 0;
        prev[0] = n - 1;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            res[cur] = deck[i];
            next[prev[cur]] = next[cur];
            prev[next[cur]] = prev[cur];
            cur = next[next[cur]];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.deckRevealedIncreasing(temp_vector({17, 13, 11, 2, 3, 5, 7})));
}

//
// Created By ASUS At 2026-02-08 19:58
//
