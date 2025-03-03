#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        if (n != t.size()) {
            return false;
        }
        vector<int> times(26, 0);
        for (int i = 0; i < n; i++) {
            times[(t[i] - s[i] + 26) % 26]++;
        }
        int total = 0;
        for (int key = 0; key < 26; key++) {
            int v = times[key];
            if (key != 0 and v != 0) {
                total = max((v - 1) * 26 + key, total);
            }
        }
        return total <= k;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.canConvertString("input", "ouput", 9) << " res" << endl;
    cout << test.canConvertString("abc", "bcd", 10) << " res" << endl;
    cout << test.canConvertString("aab", "bbb", 27) << " res" << endl;
}


//
// Created by ASUS on 2025/2/24.
//
