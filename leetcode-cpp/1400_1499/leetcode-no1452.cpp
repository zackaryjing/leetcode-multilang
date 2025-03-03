#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class MyBitset {
    int64_t *data = nullptr;
    int _size;

public:
    explicit MyBitset(int n) {
        _size = ceil(n / 64.0);
        data = new int64_t[_size]();
    }

    MyBitset(): _size(0) {
    }


    void set(int n) {
        data[n / 64] |= 1LL << n % 64;
    }

    MyBitset operator&(const MyBitset &other) const {
        assert(_size == other._size && "Size not equal");
        MyBitset temp(_size * 64);
        for (int i = 0; i < _size; i++) {
            temp.data[i] = data[i] & other.data[i];
        }
        return temp;
    }

    MyBitset(const MyBitset &other) {
        _size = other._size;
        data = new int64_t[_size];
        for (int i = 0; i < _size; i++) {
            data[i] = other.data[i];
        }
    }

    bool in(MyBitset &other) {
        assert(_size == other._size && "Size not equal");
        for (int i = 0; i < _size; i++) {
            if (data[i] != (data[i] & other.data[i])) {
                return false;
            }
        }
        return true;
    }

    ~MyBitset() {
        delete[] data;
    }
};

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string> > &favoriteCompanies) {
        // bitset不支持运行时指定大小，所以就自己实现一个喽
        pmr::unordered_map<string, bitset<100> > data;
        int n = favoriteCompanies.size();
        pmr::unordered_set<string> comps;
        for (int i = 0; i < n; i++) {
            auto &companies = favoriteCompanies[i];
            for (auto &company: companies) {
                data[company].set(i);
                comps.insert(company);
            }
        }
        int type_num = comps.size();
        vector peoples(n, MyBitset(type_num));
        int times = 0;
        for (auto [key,val]: data) {
            for (int i = 0; i < n; i++) {
                if (val[i]) {
                    peoples[i].set(times);
                }
            }
            times++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (peoples[i].in(peoples[j])) {
                        valid = false;
                    }
                }
            }

            if (valid) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<string> > eg1 = {
        {"leetcode", "google", "facebook"}, {"google", "microsoft"}, {"google", "facebook"}, {"google"}, {"amazon"}
    };
    auto res1 = test.peopleIndexes(eg1);
    cout << res1.size() << endl;
    show_vector(res1);
}

class Solution2 {
public:
    vector<int> peopleIndexes(vector<vector<string> > &favoriteCompanies) {
        // 效率太低了
        pmr::unordered_map<string, pmr::unordered_set<int> > data;
        int n = favoriteCompanies.size();
        for (int i = 0; i < n; i++) {
            auto &list = favoriteCompanies[i];
            for (const auto &company: list) {
                data[company].insert(i);
            }
        }

        // for (auto &[key,val]: data) {
        //     cout << key << ": ";
        //     for (auto &h: val) {
        //         cout << h << ", ";
        //     }
        //     cout << endl;
        // }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // cout << i << " <--" << endl;
            auto &list = favoriteCompanies[i];
            auto res = data[*list.begin()];
            bool valid = false;
            for (const auto &company: list) {
                // cout << company << endl;
                pmr::unordered_set<int> temp;
                for (int num: data[company]) {
                    if (res.contains(num) and i != num) {
                        temp.insert(num);
                        // cout << num << ", ";
                    }
                }
                // cout << endl;
                res = move(temp);

                if (res.empty()) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//
// Created by ASUS on 2025/2/26.
//
