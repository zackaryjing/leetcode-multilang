#include <unordered_map>
#include <memory>
#include <queue>
#include <ranges>
#include <vector>
#include<iostream>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> times;
        for (auto num: nums) {
            times[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > data;
        for (const auto &[v,t]: times) {
            data.emplace(t, v);

            if (data.size() > k) {
                data.pop();
            }
        }

        vector<int> ans;
        while (!data.empty()) {
            auto [t,v] = data.top();
            // cout << t << ", " << v << endl;
            data.pop();
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> res = test.topKFrequent(*make_unique<vector<int> >(vector{1, 1, 1, 2, 2, 3}), 2);
    show_vector(res);
    vector<int> res1 = test.topKFrequent(*make_unique<vector<int> >(vector{1, 2}), 2);
    show_vector(res1);
}


//
// Created by ASUS on 2025/2/22.
//
