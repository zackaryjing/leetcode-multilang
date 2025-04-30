#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <tuple>

using namespace std;

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        // 转换力场
        vector<tuple<int, int, int, int>> fields;
        for (auto& f : forceField) {
            int i = f[0], j = f[1], k = f[2];
            fields.push_back({i-k/2, j-k/2, i+k/2, j+k/2});
        }
        // 定义缓存，避免重复计算
        unordered_map<long long, tuple<int, int, int, int>> cache;
        // 定义当前相交的区域
        unordered_set<tuple<int, int, int, int>> currentmutil;
        int times = 0;
        while (times == 0 || currentmutil.size() != 0) {
            vector<tuple<int, int, int, int>> topro;
            if (times == 0) {
                topro = fields;
            } else {
                topro = vector<tuple<int, int, int, int>>(currentmutil.begin(), currentmutil.end());
            }
            currentmutil.clear();
            // 计算两两相交的区域
            for (int i = 0; i < topro.size(); ++i) {
                for (int j = i+1; j < topro.size(); ++j) {
                    auto temp = getcmn(cache, topro[i], topro[j]);
                    if (temp != make_tuple(0, 0, 0, 0)) {
                        currentmutil.insert(temp);
                    }
                }
            }
            ++times;
        }
        return times;
    }

private:
    // 定义缓存函数，减少计算量
    tuple<int, int, int, int> getcmn(unordered_map<long long, tuple<int, int, int, int>> &cache, tuple<int, int, int, int>& first, tuple<int, int, int, int>& second) {
        long long key = (long long)&first + (long long)&second;
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        // 计算两个矩形相交的区域
        int f0 = get<0>(first), f1 = get<1>(first), f2 = get<2>(first), f3 = get<3>(first);
        int s0 = get<0>(second), s1 = get<1>(second), s2 = get<2>(second), s3 = get<3>(second);
        if (f2 < s0 || f3 < s1 || f1 > s3 || f0 > s2) {
            return make_tuple(0, 0, 0, 0);
        }
        auto res = make_tuple(max(f0, s0), max(f1, s1), min(f2, s2), min(f3, s3));
        cache[key] = res;
        return res;
    }
};

int main(){
    cout << "GOOD";
}
//
// Created by ASUS on 2023/4/22.
//
