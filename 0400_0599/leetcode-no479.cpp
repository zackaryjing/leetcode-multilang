#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid(long num,int n){
        long x = sqrt(num) + 1;
        long size = pow(10,n - 1);
        while (x >= size and num / x >= size and x <= size * 10 and num / x <= size * 10){
            if (x * (num / x) == num) {
                return true;
            } else {
                x--;
            }
        }
        return false;
    }
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        long begin = 0,i = 0;
        while (i < n) {
            begin *= 10;
            begin += 9;
            i += 1;
        }
        while (true) {
            long half = begin;
            long half_copy = half;
            while (half_copy > 0) {
                half *= 10;
                half += half_copy % 10;
                half_copy /= 10;
            }
            if (valid(half,n)) {
                return half % 1337;
            }
            begin--;
        }
    }
};

int main() {
    Solution test;
    cout << test.valid(9009,2) << endl;
    cout << test.valid(1872,2) << endl;
    cout << test.valid(1243,2) << endl;
    cout << test.valid(791,2) << endl;
    cout << string(30,'-') << endl;
    cout << test.largestPalindrome(1) << endl;
    cout << string(30,'-') << endl;
    cout << test.largestPalindrome(2) << endl;
    cout << string(30,'-') << endl;
    cout << test.largestPalindrome(3) << endl;
    cout << string(30,'-') << endl;
    cout << test.largestPalindrome(4) << endl;
}
//
// Created by ASUS on 2024/2/27.
//
