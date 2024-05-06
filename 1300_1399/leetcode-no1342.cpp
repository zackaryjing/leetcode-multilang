#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            if (num % 2) num--;
            else num /= 2;
            ans ++;
        }
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.numberOfSteps(14) << endl;
    cout << test.numberOfSteps(8) << endl;
    cout << test.numberOfSteps(123) << endl;
}
//
// Created by ASUS on 2023/7/19.
//
