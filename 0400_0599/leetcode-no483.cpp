#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num;
        num = stoll(n);
        auto maxm = (long long)(log(num)/(log(2)));
        cout << maxm << endl;
        for (long long m = maxm;m>=2 ;m--){
            auto k = (long long)pow(num,1.0/m);
//            cout << k << " " << endl;
            cout << m << " " << k << " " << (1-pow(k,m + 1))/(1-k) << endl;
            if ((1-pow(k,m + 1))/(1-k) == num) {
                return to_string(k);
            }
        }
        return  to_string(num - 1);
    }
};
int main(){
    Solution test;
//    cout << test.smallestGoodBase("1000000000000") << endl;
//    cout << test.smallestGoodBase("4681") << endl;
    cout << test.smallestGoodBase("14919921443713777") << endl;
}
//
// Created by ASUS on 2023/7/7.
//
