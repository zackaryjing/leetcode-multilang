// problem: https://leetcode.cn/problems/implement-router/
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;


// time spent: 1:48:40

struct pair_hash {
    size_t operator()(const pair<int, int> &p) const {
        return static_cast<size_t>(p.first) * 200000 + p.second;
    }
};


class Router {
    // [Pass] ordinary [redo]
    int _limit;
    deque<array<int, 2>> packets;
    unordered_map<pair<int, int>, set<int>, pair_hash> targets;
    unordered_map<int, deque<int>> times;

public:
    Router(int memoryLimit) {
        _limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (targets[{destination, source}].contains(timestamp)) {
            return false;
        }
        if (packets.size() == _limit) {
            auto first = packets.front();
            int des = first[0];
            int src = first[1];
            auto &t = targets[{des, src}];
            t.erase(t.begin());
            packets.pop_front();
            times[des].pop_front();
        }
        targets[{destination, source}].insert(timestamp);
        packets.push_back({destination, source});
        times[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (not packets.empty()) {
            auto first = packets.front();
            int des = first[0];
            int src = first[1];
            auto &t = targets[{des, src}];
            int tmp = *t.begin();
            t.erase(t.begin());
            packets.pop_front();
            times[des].pop_front();
            return {src, des, tmp};
        }
        return {};
    }

    int getCount(int destination, int startTime, int endTime) {
        const auto &list = times[destination];
        return static_cast<int>(ranges::upper_bound(list, endTime) - ranges::lower_bound(list, startTime));
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main(int argc, char *argv[]) {
    Router router(5); // ["Router", [5]]

    // Step 1: addPacket(4,2,1)
    cout << "addPacket(4,2,1): " << (router.addPacket(4, 2, 1) ? "true" : "false") << endl; // true

    // Step 2: getCount(2,1,1)
    cout << "getCount(2,1,1): " << router.getCount(2, 1, 1) << endl; // 1

    // Step 3: forwardPacket()
    vector<int> pkt = router.forwardPacket(); // expect [4,2,1]
    cout << "forwardPacket(): [" << pkt[0] << "," << pkt[1] << "," << pkt[2] << "]" << endl;

    // Step 4: getCount(2,1,1)
    cout << "getCount(2,1,1): " << router.getCount(2, 1, 1) << endl; // 0

    // Step 5: addPacket(4,2,1)
    cout << "addPacket(4,2,1): " << (router.addPacket(4, 2, 1) ? "true" : "false") << endl; // false (duplicate)
    // Step 6: getCount(2,1,1)
    cout << "getCount(2,1,1): " << router.getCount(2, 1, 1) << endl; // 0


    return 0;
}

//
// Created By Zackary At 2025-06-13 12:25:22
//
