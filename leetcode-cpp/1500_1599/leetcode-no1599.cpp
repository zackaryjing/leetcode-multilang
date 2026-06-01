// problem:
// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int mx = 0, curCost = 0, curGain = 0, curWaiting = 0, turnCnts = 0, res = -1;
        int people = 0;
        int mask = 0b1111;
        int i = 0;
        while (curWaiting > 0 or i < n) {
            // cout << "curWaiting: " << curWaiting << endl;
            // cout << "i: " << i << endl;
            int curHandle = (i < n) ? customers[i] + curWaiting : curWaiting;
            i++;
            turnCnts += 1;
            if (curHandle == 0 and people == 0) {
                continue;
            } else {
                curCost += runningCost;
                curGain += min(curHandle, 4) * boardingCost;
                curWaiting = max(curHandle - 4, 0);
                people = ((people << 1) | 1) & mask;
                if (curGain - curCost > mx) {
                    mx = curGain - curCost;
                    res = turnCnts;
                }
                // cout << "mx: " << mx << endl;
            }
        }
        return res;
    }
};


class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int mx = 0, curCost = 0, curGain = 0, curWaiting = 0, turnCnts = 0, res = -1;
        int i = 0;
        while (curWaiting > 0 or i < n) {
            int curHandle = (i < n) ? customers[i] + curWaiting : curWaiting;
            i++;
            turnCnts += 1;
            curCost += runningCost;
            curGain += min(curHandle, 4) * boardingCost;
            curWaiting = max(curHandle - 4, 0);
            if (curGain - curCost > mx) {
                mx = curGain - curCost;
                res = turnCnts;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minOperationsMaxProfit(temp_vector({8, 3}), 5, 6) << endl;
    cout << test.minOperationsMaxProfit(temp_vector({10, 9, 6}), 6, 4) << endl;
    cout << test.minOperationsMaxProfit(temp_vector({3, 4, 0, 5, 1}), 1, 92) << endl;
    cout << test.minOperationsMaxProfit(temp_vector({10, 10, 6, 4, 7}), 3, 8) << endl;
}

//
// Created By jing At 22:44
//
