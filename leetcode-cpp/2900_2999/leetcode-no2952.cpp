#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int> &coins, int target) {
        sort(coins.begin(), coins.end());
        int my_target = 1;
        int times = 0;
        int index = 0;
        int k;
        while (my_target <= target) {
            if (index < coins.size()) {
                k = coins[index++];
            } else {
                k = INT_MAX;
            }
            if (k == my_target) {
                my_target *= 2;
                if (my_target > target) break;
            } else if (k < my_target) {
                my_target += k;
                if (my_target > target) break;
            } else {
                // add
                while (k > my_target) {
                    times++;
                    my_target = 2 * my_target;
                    if (my_target > target) break;
                }
                if (my_target > target) break;
                my_target += k;
            }
        }
        return times;
    }
};

int main() {
    Solution test;
    vector<int> test1 = {1, 4, 10};
    cout << "ans: " << test.minimumAddedCoins(test1, 19) << endl;
    cout << endl;
    vector<int> test2 = {1, 4, 10, 5, 7, 19};
    cout << "ans: " << test.minimumAddedCoins(test2, 19);
    cout << endl;
    vector<int> test3 = {1, 1, 1};
    cout << "ans: " << test.minimumAddedCoins(test3, 20);
    cout << endl;

}
//
// Created by ASUS on 2024/3/30.
//
