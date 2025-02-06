#include <iostream>
#include <vector>
#include  <algorithm>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        int i = 0;
        if (n == 0) return "0";
        while (n > 0) {
            if (i % 3 == 0 and i != 0) {
                ans += '.';
            }
            ans += static_cast<char>('0' + (n % 10));
            i++;
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution test;
    cout << test.thousandSeparator(1000000000) << endl;
}

//
// Created by ASUS on 2025/2/2.
//
