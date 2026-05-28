// problem:
// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        int maxCnt = 1200;
        vector<int> students(maxCnt);
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            students[startTime[i]]++;
            students[endTime[i] + 1]--;
        }
        // show_vector(students);
        for (int i = 1; i < maxCnt; ++i) {
            students[i] += students[i - 1];
        }
        // show_vector(students);
        return students[queryTime];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.busyStudent(temp_vector({1, 2, 3}), temp_vector({3, 2, 7}), 4) << endl;
}

//
// Created By ASUS At 2026-05-26 14:41
//
