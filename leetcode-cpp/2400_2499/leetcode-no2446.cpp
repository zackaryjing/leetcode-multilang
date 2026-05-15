// problem:
// https://leetcode.cn/problems/determine-if-two-events-have-conflict/description/?envType=problem-list-v2&envId=FeuPdeiM
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        const auto toMinute = [](string s) -> int {
            return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
        };
        int s1 = toMinute(event1[0]), s2 = toMinute(event2[0]), e1 = toMinute(event1[1]), e2 = toMinute(event2[1]);
        return not(e2 < s1 or s2 > e1);
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.haveConflict(temp_vector({"01:15", "02:00"}), temp_vector({"02:00", "03:00"})) << endl;
    cout << test.haveConflict(temp_vector({"10:00", "11:00"}), temp_vector({"14:00", "15:00"})) << endl;
}

//
// Created By jing At 2026-05-15 18:52
//
