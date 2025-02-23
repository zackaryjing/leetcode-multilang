#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;


class RangeFreqQuery {
    unordered_map<int, vector<int> > data;

public:
    RangeFreqQuery(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            data[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto it = data.find(value);
        if (it == data.end()) {
            return 0;
        }
        const vector<int> &pos = it->second;
        const auto first = lower_bound(pos.begin(), pos.end(), left);
        auto second = upper_bound(pos.begin(), pos.end(), right);
        return (second - first);
    }
};


class RangeFreqQuery_mine {
    // 一般，发现了更好的写法
    unordered_map<int, vector<int> > data;

public:
    RangeFreqQuery_mine(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            data[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        const vector<int> &pos = data[value];
        const auto first = lower_bound(pos.begin(), pos.end(), left);
        auto second = upper_bound(pos.begin(), pos.end(), right);
        if (first == pos.end()) {
            return 0;
        }
        return (second - first);
    }
};

int main(int argc, char *argv[]) {
    RangeFreqQuery_mine test(*make_unique<vector<int> >(vector{12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56}));
    cout << test.query(1, 2, 4) << endl;
    cout << test.query(0, 11, 33) << endl;
    cout << test.query(0, 11, 31) << endl;
    cout << test.query(0, 50, 31) << endl;
    cout << test.query(0, 50, 33) << endl;
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */


//
// Created by ASUS on 2025/2/18.
//
