// problem: https://leetcode.cn/problems/snapshot-array/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;

class SnapshotArray2 {
public:
    int curId = 0;
    int l;
    unordered_map<long long, int> array;
    unordered_map<int, vector<long long>> ids;
    SnapshotArray2(int length) {
    }

    void set(int index, int val) {
        array[(long long) curId << 32 | (long long) index] = val;
        ids[index].push_back(curId);
    }

    int snap() {
        return curId++;
    }

    int get(int index, int snap_id) {
        if (ids.contains(index)) {
            const auto &temp = ids[index];
            const auto pos = ranges::upper_bound(temp, snap_id);
            if (pos == temp.begin()) {
                return 0;
            }
            return array[(*prev(pos) << 32) | index];
        }
        return 0;
    }
};


class SnapshotArray {
public:
    long long curId = 0;
    vector<vector<long long>> array;
    SnapshotArray(int length) {
        array.resize(length);
    }

    void set(int index, int val) {
        if (not array[index].empty() and array[index].back() >> 32 == curId) {
            array[index].back() = (curId << 32) - val;
        } else {
            array[index].push_back((curId << 32) - val);
        }
    }

    int snap() {
        return static_cast<int>(curId++);
    }

    int get(int index, int snap_id) {
        if (array[index].empty()) {
            return 0;
        }
        const auto &temp = array[index];
        const auto t = static_cast<long long>(snap_id) << 32;
        const auto pos = ranges::upper_bound(temp, t);
        if (pos == temp.begin()) {
            return 0;
        }
        return static_cast<int>(t - *prev(pos));
    }
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(int argc, char *argv[]) {
    SnapshotArray test(3);
    test.set(0, 5);
    cout << test.snap() << endl;
    test.set(0, 6);
    cout << test.get(0, 0) << endl;
}

//
// Created By jing At 2026-05-15 19:38
//
