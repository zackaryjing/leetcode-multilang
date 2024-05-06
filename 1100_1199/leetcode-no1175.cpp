#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isprime(int num){
    int n = (int)sqrt(num);
    for (int i = 2;i <= n;i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}
class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt = 0;
        int MAX = 1E9 + 7;
        long long ans = 1;
        for (int i = 2;i <= n;i++){
            if (isprime(i)) {
                cnt ++;
                ans *= cnt;
                ans %= MAX;
            }
        }
        for (int i = n - cnt;i > 1;--i){
            ans *= i;
            ans %= MAX;
        }
        return (int)ans;
    }
};

int main(){
    Solution test;
    cout << test.numPrimeArrangements(5) << endl;
    cout << test.numPrimeArrangements(10) << endl;
    cout << test.numPrimeArrangements(100) << endl;
}
//
// Created by ASUS on 2023/8/21.
//
