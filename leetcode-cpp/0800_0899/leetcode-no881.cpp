// problem: https://leetcode.cn/problems/boats-to-save-people/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;


class Solution2 {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        ranges::sort(people);
        int start = people[0];
        int n = people.size();
        int end = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (people[i] + start <= limit) {
                end = i;
                break;
            }
        }
        int res = 0;
        int second = end;
        vector<bool> left = vector(n, true);
        for (int i = 0; i < n; ++i) {
            while (i < second) {
                if (people[i] + people[second] <= limit) {
                    left[second] = false;
                    left[i] = false;
                    res++;
                    second -= 1;
                    break;
                }
                second -= 1;
            }
            if (i >= second) {
                res += ranges::count(left, true);
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        ranges::sort(people);
        const int start = people[0];
        const int n = people.size();
        int res = 0;
        int second = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (people[i] + start <= limit) {
                second = i;
                break;
            }
        }
        if (second == 0) {
            return n;
        }
        for (int i = 0; i < n; ++i) {
            bool ended = true;
            while (i < second) {
                if (people[i] + people[second] <= limit) {
                    ended = false;
                    res++;
                    second -= 1;
                    break;
                }
                second -= 1;
            }
            if (ended) {
                res += n - res * 2;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.numRescueBoats(temp_vector({3, 5, 3, 4}), 5) << " e4" << endl;
    cout << test.numRescueBoats(temp_vector({3, 2, 2, 1}), 3) << " e3" << endl;
    cout << test.numRescueBoats(temp_vector({1, 2}), 3) << " e1" << endl;
    cout << test.numRescueBoats(temp_vector({3, 2, 3, 2, 2}), 6) << " e3" << endl;
    cout << test.numRescueBoats(temp_vector({2, 4}), 5) << " e2" << endl;
}

//
// Created By jing At 2025-10-25 16:30
//
