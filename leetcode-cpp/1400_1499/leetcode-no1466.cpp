#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int> > &connections) {
        vector<vector<pair<int, bool> > > paths(n);
        int ans = 0;
        for (auto connection: connections) {
            int s = connection[0], e = connection[1];
            paths[s].emplace_back(e, false);
            paths[e].emplace_back(s, true);
        }

        auto dfs = [&](auto &&self, int start, int from) -> void {
            // 必须指定返回类型
            for (const auto &[nxt, is_reverse]: paths.at(start)) {
                if (nxt != from) {
                    if (!is_reverse) {
                        // 需要反转的边
                        ans++;
                    }
                    self(self, nxt, start); // 必须传递 self 自身
                }
            }
        };

        dfs(dfs, 0, -1); // 初始调用：传递 lambda 自身作为第一个参数
        return ans;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg0 = {{0, 2}, {0, 3}, {4, 1}, {4, 5}, {5, 0}};
    cout << test.minReorder(6, eg0) << endl;;
    vector<vector<int> > eg1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << test.minReorder(6, eg1) << endl;;
    vector<vector<int> > eg2 = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    cout << test.minReorder(5, eg2) << endl;;
    vector<vector<int> > eg3 = {{1, 0}, {2, 0}};
    cout << test.minReorder(3, eg3) << endl;
}


//
// Created by ASUS on 2025/3/8.
//
