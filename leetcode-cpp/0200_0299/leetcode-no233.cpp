#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int k = 0,ans = 0;
        while (n >= pow(10,k)){
            ans += (int)((n / (long long)pow(10,k + 1)) * (long long)pow(10,k) +
                    min((long long)max((int)(n % (long long)pow(10,k + 1) - (long long)pow(10,k) + 1),0), (long long)pow(10,k)));
//            cout << ans << endl;
            k++;
        }
        return ans;
    }
};


int main(){
    Solution test;
    cout << test.countDigitOne(13) << endl;
    cout << test.countDigitOne(100000000000) << endl;
}
//
// Created by ASUS on 2023/7/29.
//
