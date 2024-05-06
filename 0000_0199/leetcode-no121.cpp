#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0,biggest = 0;
        for (auto j = prices.rbegin();j != prices.rend(); j++){
            biggest = max(biggest,*j);
            ans = max(biggest - *j,ans);
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {7,1,5,3,6,4};
    cout << test.maxProfit(eg1) << endl;
}
//
// Created by ASUS on 2023/7/25.
//
