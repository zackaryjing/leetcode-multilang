#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        k = pow(2, n) - k - 1;
        int times = 0;
        while (n > 0) {
            int mid = pow(2, n - 1) - 1;
            if (k < mid) {
                //k = 0 ,mid = 1
                k = 2 * mid - k;
                times++;
            } else if (k == mid) {
                if (mid == 0) {
                    return times % 2 ? '1' : '0';
                }
                return times % 2 ? '0' : '1';
            }
            k -= mid + 1;
            n--;
        }
        return times % 2 ? '1' : '0';
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.findKthBit(4, 0) << endl;
    cout << test.findKthBit(4, 1) << endl;
    cout << test.findKthBit(4, 2) << endl;
    cout << test.findKthBit(4, 3) << endl;
    cout << test.findKthBit(4, 4) << endl;
    cout << test.findKthBit(4, 5) << endl;
    cout << test.findKthBit(4, 6) << endl;
    cout << test.findKthBit(4, 7) << endl;
    cout << test.findKthBit(4, 8) << endl;
    cout << test.findKthBit(4, 9) << endl;
    cout << test.findKthBit(4, 10) << endl;
    cout << test.findKthBit(4, 11) << endl;
    cout << test.findKthBit(4, 12) << endl;
    cout << test.findKthBit(4, 13) << endl;
    cout << test.findKthBit(4, 14) << endl;
}


//
// Created by ASUS on 2025/2/24.
//
