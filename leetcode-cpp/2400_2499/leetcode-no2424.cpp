// problem: https://leetcode.cn/problems/longest-uploaded-prefix/
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

class LUPrefix {
    int last = 0;
    bitset<100010> data;
    int n = 0;

public:
    LUPrefix(int n) {
        this->n = n;
        data.set(0);
    }

    void upload(int video) {
        data.set(video);
        if (video == last + 1) {
            while (data[last + 1]) {
                last++;
            }
        }
    }

    int longest() {
        return last;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

int main(int argc, char *argv[]) {
    LUPrefix *server = new LUPrefix(4);
    server->upload(3);
    cout << server->longest() << "\n"; // Expected: 0
    server->upload(1);
    cout << server->longest() << "\n"; // Expected: 1
    server->upload(2);
    cout << server->longest() << "\n"; // Expected: 3
    delete server;
    return 0;
}

//
// Created By Zackary At 2025-05-29 22:00:35
//
