#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 1 % k,len = 1;
        if (k % 2 == 0 or k % 5 == 0) {
            return -1;
        } else {
            while (res != 0){
                res = (res * 10 + 1) % k;
                len ++;
            }
        }
        return len;
    }
};


int main(){
    Solution test;
    cout << test.smallestRepunitDivByK(1) << endl;
    cout << test.smallestRepunitDivByK(2) << endl;
    cout << test.smallestRepunitDivByK(3) << endl;

}
//
// Created by ASUS on 2023/7/14.
//
