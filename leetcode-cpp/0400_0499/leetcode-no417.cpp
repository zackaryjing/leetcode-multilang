#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <set>

using namespace std;

void show(set<pair<int, int> > target) {
    for (auto [k,i]: target) {
        cout << k << ", " << i << endl;
    }
}

class Solution {
public:
    // Solution() {
    // }

    set<pair<int, int> > atlantic;
    set<pair<int, int> > pacific; // TODO: 改进意见：没必要使用set，这里可以使用一个array或者vector去表示，单元格是否属于pac或者atl
    vector<vector<int> > _heights;
    int n, m;

    void getBelonging(deque<pair<int, int> > &toVis, set<pair<int, int> > &target) {
        vector<pair<int, int> > directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (not toVis.empty()) {
            auto cur = toVis.front();
            toVis.pop_front();
            if (target.find(cur) == target.end()) {
                auto value = _heights[cur.first][cur.second];
                for (auto [dy,dx]: directions) {
                    int newy = cur.first + dy;
                    int newx = cur.second + dx;
                    if (newx < m and newx >= 0 and newy < n and newy >= 0) {
                        if (_heights[newy][newx] >= value) {
                            toVis.emplace_back(newy, newx);
                        }
                    }
                }
            }
            target.insert(cur);
            // 添加到 atlanticTovis （遍历完成之后）
        }
    }

    vector<vector<int> > pacificAtlantic(vector<vector<int> > &heights) {
        _heights = heights;
        n = heights.size();
        m = heights[0].size();
        deque<pair<int, int> > atlanticToVis;
        deque<pair<int, int> > pacificToVis;
        for (int i = 0; i < n; i++) {
            atlanticToVis.emplace_back(i, m - 1);
            pacificToVis.emplace_back(i, 0);
        }

        for (int i = 0; i < m; i++) {
            pacificToVis.emplace_back(0, i);
            atlanticToVis.emplace_back(n - 1, i);
        }

        getBelonging(atlanticToVis, atlantic);
        getBelonging(pacificToVis, pacific);
        vector<pair<int, int> > result;

        set_intersection(atlantic.begin(), atlantic.end(), pacific.begin(), pacific.end(), back_inserter(result));
        vector<vector<int> > res;
        transform(result.begin(), result.end(), back_inserter(res), [](const pair<int, int> &p) {
            return vector<int>{p.first, p.second};
        });
        return res;
    }
};


int main() {
    Solution test;
    vector<vector<int> > heights1 = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}
    };
    auto res = test.pacificAtlantic(heights1);
    // cout << 1 << endl;
    for (auto k: res) {
        cout << k[0] << ", " << k[1] << endl;
    }
}

// Created by ASUS on 2025/2/7.
//
