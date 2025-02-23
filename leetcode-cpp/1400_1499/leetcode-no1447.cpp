#include <iostream>
#include <set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (a != 0) {
            int temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }

    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        set<int> vis;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                int cd = gcd(j, i);
                if (cd == 1) {
                    ans.emplace_back(to_string(j) + "/" + to_string(i));
                    // 使用emplace_back回避push_back更快
                }
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    int gcd(int a, int b) {
        while (a != 0) {
            int temp = a;
            a = b % a;
            b = temp;
        }
        return b;
    }

    vector<string> simplifiedFractions(int n) {
        set<string> ans;
        set<int> vis;
        for (int i = n; i >= 2; i--) {
            if (not vis.contains(i)) {
                for (int j = i - 1; j >= 1; j--) {
                    int cd = gcd(j, i);
                    ans.insert(to_string(j / cd) + "/" + to_string(i / cd));
                    if (cd != 1) {
                        vis.insert(i / cd);
                    }
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<string> res1 = test.simplifiedFractions(2);
    show_vector(res1);
    vector<string> res2 = test.simplifiedFractions(3);
    show_vector(res2);
    vector<string> res3 = test.simplifiedFractions(6);
    show_vector(res3);
}


//
// Created by ASUS on 2025/2/22.
//
