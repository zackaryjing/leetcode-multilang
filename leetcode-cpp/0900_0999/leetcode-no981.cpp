// problem: https://leetcode.cn/problems/time-based-key-value-store/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <c++/14/unordered_map>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> umap;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        umap[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto &list = umap[key];
        auto t = ranges::upper_bound(list, timestamp, [](const auto &a, const auto &b) -> bool { return a < b.first; });
        if (t == list.begin()) {
            return "";
        }

        return (*--t).second;
        // return prev(t)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(int argc, char *argv[]) {
    TimeMap test;
    test.set("foo", "bar", 1);
    cout << test.get("foo", 1) << " bar\n";
    cout << test.get("foo", 3) << " bar\n";
    test.set("foo", "bar2", 4);
    cout << test.get("foo", 4) << " bar2\n";
    cout << test.get("foo", 5) << " bar2\n";
}

//
// Created By jing At 2026-05-13 19:59
//
