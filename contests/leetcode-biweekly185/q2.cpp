// problem:
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int minLights(vector<int> &lights) {
        int cur = 0, n = lights.size();
        vector status = lights;
        for (int i = 0; i < n; ++i) {
            int light = lights[i];
            if (cur > 0)
                status[i] = 1;
            cur = max(light, cur - 1);
        }
        cur = 0;
        for (int i = n - 1; i >= 0; --i) {
            int light = lights[i];
            if (cur > 0)
                status[i] = 1;
            cur = max(light, cur - 1);
        }
        // show_vector(status);
        int cnts = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (status[i] == 0) {
                cnts++;
            } else {
                res += (cnts + 2) / 3;
                cnts = 0;
            }
        }
        res += (cnts + 2) / 3;
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.minLights(temp_vector({0, 0, 0, 0})) << endl;
    cout << test.minLights(temp_vector({0, 0, 0, 2, 0})) << endl;
    cout << test.minLights(temp_vector({3, 1, 0, 0, 0, 0, 0, 1, 3})) << endl;
}

//
// Created By ASUS At 2026-06-20 22:44
//
