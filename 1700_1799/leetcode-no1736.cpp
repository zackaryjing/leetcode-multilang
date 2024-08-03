#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?' and (time[1] <= '3' or time[1] == '?')) {
            time[0] = '2';
        } else if (time[0] == '?') {
            time[0] = '1';
        }
        if (time[1] == '?') {
            if (time[0] == '2') {
                time[1] = '3';
            } else {
                time[1] = '9';
            }
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};

int main() {
    Solution test;
    cout << test.maximumTime("2?:?0") << endl;
    cout << test.maximumTime("?4:??") << endl;
    cout << test.maximumTime("2?:?0") << endl;
    cout << test.maximumTime("?0:?0") << endl;
}
//
// Created by ASUS on 2024/8/3.
//
