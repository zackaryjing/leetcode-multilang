#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int time) {
        (void) time;
        sort(clips.begin(), clips.end(),
//             [](const vector<int> &a, const vector<int> &b) {
//                 return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
//             });
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] < b[1] || a[0] < b[0];
             });
        int max_length = clips.back()[1];

        if (time > max_length) {
            return -1;
        }
        vector<int> dp(max_length + 1, INT_MAX);
        dp[0] = 0;
        int last = 0;
        for (auto clip: clips) {
            if (clip[1] == last) {
                continue;
            }
            last = clip[1];
            if (dp[clip[0]] == INT_MAX) {
                continue;
            }
            dp[clip[1]] = min(dp[clip[0]] + 1, dp[clip[1]]);
            for (int k = clip[1] - 1; k >= clip[0]; k--) {
                dp[k] = min(dp[k + 1], dp[k]);
            }
        }

//        for (auto k: dp) {
//            cout << k << " ";
//        }
//        cout << endl;

        for (auto i: clips) {
            for (auto k: i) {
                cout << k << " ";
            }
            cout << endl;
        }

        return dp[time] == INT_MAX ? -1 : dp[time];

    }
};

int main() {
    Solution test;
    vector<vector<int>> array = {{0, 0},
                                 {0, 2},
                                 {4, 6},
                                 {8, 10},
                                 {1, 9},
                                 {1, 5},
                                 {5, 9}};
    cout << test.videoStitching(array, 10) << endl;
    vector<vector<int>> array2 = {{0, 1},
                                  {1, 2}};
    cout << test.videoStitching(array2, 5) << endl;
    vector<vector<int>> array3 = {{0, 1},
                                  {6, 8},
                                  {0, 2},
                                  {5, 6},
                                  {0, 4},
                                  {0, 3},
                                  {6, 7},
                                  {1, 3},
                                  {4, 7},
                                  {1, 4},
                                  {2, 5},
                                  {2, 6},
                                  {3, 4},
                                  {4, 5},
                                  {5, 7},
                                  {6, 9}};
    cout << test.videoStitching(array3, 9) << endl;
    vector<vector<int>> array4 = {{0, 2},
                                  {4, 8}};
    cout << test.videoStitching(array4, 5) << endl;
    vector<vector<int>> array5 = {{0, 0},
                                  {9, 9},
                                  {2, 10},
                                  {0, 3},
                                  {0, 5},
                                  {3, 4},
                                  {6, 10},
                                  {1, 2},
                                  {4, 7},
                                  {5, 6}};
    cout << test.videoStitching(array5, 5) << endl;

}
//
// Created by ASUS on 2024/9/2.
//
