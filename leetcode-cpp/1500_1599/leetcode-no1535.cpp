#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        size_t cur = 0;
        size_t n = arr.size();
        k = min(k, static_cast<int>(n) - 1);

        int times = 0;
        while (true) {
            auto nxt = (cur + 1) % n;
            // cout << "cur: " << cur << " val: " << arr[cur] << " nxt: " << arr[nxt] << endl;
            if (arr[cur] > arr[nxt]) {
                while (arr[cur] > arr[nxt]) {
                    swap(arr[cur], arr[nxt]);
                    cur = nxt;
                    times++;
                    if (times >= k) {
                        return arr[nxt];
                    }
                    nxt = (cur + 1) % n;
                }
            } else {
                if (times >= k) {
                    return arr[cur];
                }
                cur = nxt;
            }
            times = 1;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.getWinner(*make_unique<vector<int> >(vector{1, 25, 35, 42, 68, 70}), 1) << endl;
    cout << test.getWinner(*make_unique<vector<int> >(vector{2, 1, 3, 5, 4, 6, 7}), 2) << endl;
    cout << test.getWinner(*make_unique<vector<int> >(vector{1, 25, 35, 42, 68, 70}), 10) << endl;
    cout << test.getWinner(*make_unique<vector<int> >(vector{3, 2, 1}), 10) << endl;
    cout << test.getWinner(*make_unique<vector<int> >(vector{1, 9, 8, 2, 3, 7, 6, 4, 5}), 7) << endl;
    cout << test.getWinner(*make_unique<vector<int> >(vector{1, 11, 22, 33, 44, 55, 66, 77, 88, 99}), 1000000000) <<
            endl;
}


//
// Created by ASUS on 2025/2/24.
//
