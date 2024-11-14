#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto k : nums) {
            if (not (to_string(k).size() % 2)){
//                cout << to_string(k).size() << " " << (to_string(k).size() % 2) << " " << endl;
                ans ++;
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {12,345,2,6,7896};
    cout << test.findNumbers(eg1) << endl;
}
//
// Created by ASUS on 2023/7/15.
//
