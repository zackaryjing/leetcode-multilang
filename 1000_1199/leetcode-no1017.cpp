#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        while (n != 0){
            ans += (n & 1) ? '1' : '0';
            n -= (n & 1);
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.baseNeg2(2) << endl;
}
//
// Created by ASUS on 2023/7/18.
//
