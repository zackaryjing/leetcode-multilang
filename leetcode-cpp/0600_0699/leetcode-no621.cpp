#include <iostream>
#include <map>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    map<char, int> len;
    vector<int> data;
public:
    int leastInterval(vector<char> &tasks, int n) {
        for (auto j: tasks) {
            len[j]++;
        }
        for (auto [key, val]: len) {
            data.push_back(val);
        }
        sort(data.begin(), data.end(), [](const int a, const int b) { return a > b; });
        int row = 0, maxk = 0;
        int maxn = data[0] - 1;
        int left = 0;
        int total = 0;
        for (auto task: data) {
            total += task;
            if (task == maxn + 1) {
                row++;
                maxk++;
                continue;
            }
            if (task >= left) {
                row++;
                left = maxn - (task - left);
            } else {
                left = left - task;
            }
        }
        if (row > n + 1) {
            return total;
        } else {
            return (n + 1) * (maxn + 1) - (n + 1 - maxk);
        }
    }
};

int main() {
    Solution test;
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << test.leastInterval(tasks1, 2) << endl;
    cout << endl;
    Solution test2;
    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << test2.leastInterval(tasks2, 0) << endl;
    cout << endl;
    Solution test3;
    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << test3.leastInterval(tasks3, 2) << endl;
    cout << endl;
    Solution test4;
    vector<char> tasks4 ={ 'A','C','A','B','D','B' } ;
    cout << test4.leastInterval(tasks4, 1) << endl;

}
//
// Created by ASUS on 2024/3/30.
//
