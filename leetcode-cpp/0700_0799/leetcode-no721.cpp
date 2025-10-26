// problem: https://leetcode.cn/problems/accounts-merge/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

#include <ranges>
class Solution {
public:
    // TLE , not submitted
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        unordered_map<string, vector<set<string>>> pos;
        for (auto list: accounts) {
            pos[list[0]].push_back(list | views::drop(1) | ranges::to<set<string>>());
        }
        for (auto [name, list]: pos) {
            cout << name << "  ";
            for (auto vec: list) {
                for (auto addr: vec) {
                    cout << addr << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        for (auto &[name, addrs]: pos) {
            bool hasInter = true;
            int i = 0;
            while (hasInter) {
                hasInter = false;
                int m = addrs.size();
                while (i < m) {
                    for (int j = i + 1; j < m; ++j) {
                        set<string> inter;
                        ranges::set_intersection(addrs[i], addrs[j], inserter(inter, inter.begin()));
                        if (not inter.empty()) {
                            // cout << "inter: " << *inter.begin() << endl;
                            hasInter = true;
                            addrs[i].insert(addrs[j].begin(), addrs[j].end());
                            addrs.erase(addrs.begin() + j);
                            break;
                        }
                    }
                    if (hasInter) {
                        break;
                    }
                    i++;
                }
            }
        }
        vector<vector<string>> res;
        for (auto [name, addrs]: pos) {
            for (const auto &addr: addrs) {
                auto temp = vector(addr.begin(), addr.end());
                ranges::sort(temp);
                temp.insert(temp.begin(), name);
                res.push_back(temp);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(test.accountsMerge(temp_vector<vector<string>>({{"John", "johnsmith@mail.com", "john00@mail.com"},
                                                                {"John", "johnnybravo@mail.com"},
                                                                {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                                                {"Mary", "mary@mail.com"}})));
    cout << "[[ 'John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com' ], [ 'John', "
            "'johnnybravo@mail.com' ], [ 'Mary', 'mary@mail.com' ]] ";
}

//
// Created By jing At 2025-10-24 12:58
//
