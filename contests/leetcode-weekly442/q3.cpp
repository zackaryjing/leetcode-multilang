// problem: NAME
#include <iostream>
#include <numeric>
#include <vector>

#include "../utils/vector_helper.h"

using namespace std;

class Solution {
    // 学无止境
public:
    long long minTime(vector<int> &skill, vector<int> &mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> last_finish(n);
        for (int j = 0; j < m; j++) {
            long long sum_t = 0;
            for (int i = 0; i < n; i++) {
                sum_t = max(sum_t, last_finish[i]) + skill[i] * mana[j];
            }
            for (int k = n - 1; k >= 0; k--) {
                last_finish[k] = sum_t;
                sum_t -= skill[k] * mana[j];
            }
        }
        return last_finish[n - 1];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<int> eg1 = {1, 5, 2, 4}, eg2 = {5, 1, 4, 2};
    cout << test.minTime(eg1, eg2) << endl;
    vector<int> eg3 = {1, 1, 1}, eg4 = {1, 1, 1};
    cout << test.minTime(eg3, eg4) << endl;
    vector<int> eg5 = {1, 2, 3, 4}, eg6 = {1, 2};
    cout << test.minTime(eg5, eg6) << endl;
}

class Solution2 {
public:
    long long minTime(vector<int> &skill, vector<int> &mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> end_time(n);
        vector<long long> prefix_sum(n);
        long long base = 0LL;
        long long pre_sum = 0LL;
        for (int i = 0; i < n; i++) {
            end_time[i] = base + skill[i] * mana[0];
            base = end_time[i];
            prefix_sum[i] = pre_sum + skill[i];
            pre_sum = prefix_sum[i];
        }
        // show_vector(end_time);
        // cout << "prefix:";
        // show_vector(prefix_sum);

        for (int i = 1; i < m; i++) {
            int attempt = 0;
            long long start_time = end_time[0];
            while (attempt < n) {
                // cout << "a:" << attempt << endl;
                if (attempt != 0) {
                    long long new_time = end_time[attempt] - prefix_sum[attempt - 1] * mana[i];
                    if (new_time <= start_time) {
                        attempt++;
                        continue;
                    } else {
                        start_time = new_time;
                    }
                }
                // cout << "start_time: " << start_time << endl;
                bool valid = true;
                long long b = start_time;
                for (int j = 0; j < n; j++) {
                    if (b < end_time[j]) {
                        valid = false;
                        break;
                    }
                    b += skill[j] * mana[i];
                    // cout << b << "<-" << end_time[j] << endl;
                }
                if (valid) {
                    end_time[0] = start_time + skill[0] * mana[i];
                    for (int j = 1; j < n; j++) {
                        end_time[j] = end_time[j - 1] + skill[j] * mana[i];
                    }
                    break;
                }
                attempt++;
            }
            // show_vector(end_time);
        }
        return end_time.back();
    }
};


//
// Created by ASUS on 2025/3/23.
//
