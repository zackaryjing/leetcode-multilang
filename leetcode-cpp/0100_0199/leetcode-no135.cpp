// problem: https://leetcode.cn/problems/candy/?envType=daily-question&envId=2025-06-02
#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;


// time spent 26:35

class Solution2 {
public:
    // [Pass] so simple?
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector left(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int last = left[n - 1];
        int res = left[n - 1];
        // show_vector(left);
        for (int j = n - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                last++;
            } else {
                last = 1;
            }
            res += max(last, left[j]);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution2 test;
    cout << test.candy(temp_vector({1,0,2})) << endl;
    cout << test.candy(temp_vector({1,2,2})) << endl;
    cout << test.candy(temp_vector({1,2,87,87,87,2,1})) << endl;
}

//
// Created By Zackary At 2025-06-02 12:34:46
//
