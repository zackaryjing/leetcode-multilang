// problem: https://leetcode.cn/problems/rle-iterator/?envType=problem-list-v2&envId=3rBpGyas
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class RLEIterator {
    vector<int> encoding;
    int curIndex = 0;

public:
    RLEIterator(vector<int> &encoding) : encoding(encoding) {
    }

    int next(int n) {
        while (curIndex < encoding.size() and encoding[curIndex] < n) {
            n -= encoding[curIndex];
            curIndex += 2;
        }
        if (curIndex >= encoding.size()) {
            return -1;
        }
        encoding[curIndex] -= n;
        return encoding[curIndex + 1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

int main(int argc, char *argv[]) {
    RLEIterator obj(temp_vector({3, 8, 0, 9, 2, 5}));
    cout << obj.next(2) << endl;
    cout << obj.next(1) << endl;
    cout << obj.next(1) << endl;
    cout << obj.next(2) << endl;
}

//
// Created By Zackary At 2025-10-23 02:04:22
//
