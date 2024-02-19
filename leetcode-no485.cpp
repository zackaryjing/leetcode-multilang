#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int tmp = 0;
        for (auto j : nums){
            if (j != 1){
                ans = max(ans,tmp);
                tmp = 0;
            } else {
                tmp++;
            }
        }
        ans = max(ans,tmp);
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 ={ 1,1,0,1,1,1 };
    cout << test.findMaxConsecutiveOnes(eg1) << endl;
}
//
// Created by ASUS on 2023/9/6.
//
