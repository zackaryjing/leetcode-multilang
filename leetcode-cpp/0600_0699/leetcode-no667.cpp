#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int big = n,small = 1,i = 1;
        ans.push_back(big);
        big --;
        while (i != k){
            ans.push_back(small);
            small ++;
            i++;
            if (i != k){
                ans.push_back(big);
                big--,i++;
            }
        }
        if (k % 2){
            for (int e = big;e >= small;e--){
                ans.push_back(e);
            }
        } else {
            for (int e = small;e <= big;e++){
                ans.push_back(e);
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> res;
    res = test.constructArray(3,1);
    for (auto each : res) cout << each << " ";
    cout << endl;
    res = test.constructArray(3,2);
    for (auto each : res) cout << each << " ";
    cout << endl;
    res = test.constructArray(7,3);
    for (auto each : res) cout << each << " ";
    cout << endl;
    res = test.constructArray(7,4);
    for (auto each : res) cout << each << " ";
    cout << endl;
    res = test.constructArray(5,2);
    for (auto each : res) cout << each << " ";
    cout << endl;
}
//
// Created by ASUS on 2023/8/14.
//


/*
 [3,2] 3 1 2         2
 [4,3] 4 1 3 2
 [5,4] 5 1 4 2 3
 [6,5] 6 1 5 2 4 3
 [7,6] 7 1 6 2 5 3 4


 [3,1] 1 2 3         1
 [4,1] 1 2 3 4 / 4 3 2 1
 [4,2] 4 2 1 3 / 4 3 1 2 /
 [5,1] 1 4 2 5 3
 [5,2] 4 5 1 2 3 (1,4)
 [5,3] 5 1 4 3 2 (1)
 [5,2] 1 4 5 2 3 (3,1)
 [5,3] 1 5 4 2 3 (1)
 [5,3] 5 4 1 2 3 (1)
 [5,3] 5 1 2 4 3 (1)

 [7,3] 1 6 2 5 7 3 4
        5 4 3 2 4 1
 */
