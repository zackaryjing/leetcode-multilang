#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        // i is the start of the pattern
        int n = arr.size();
        for (int i = 0;i <= n - m;++i){
            int patterncnt = 0;
            // j is the start of to match pos
                // check if match
                bool valid = true;
                // t is the current check pos
                for (int t = j; t < j + m; ++t) {
                    if (arr[j+t] != arr[i+t]) {
                        valid = false;
                        break;
                    } else {
                        t += m - 1;
                    }
                }
                if (valid) patterncnt++;
            }
            if (patterncnt >= k) return true;
        }
        return false;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,2,4,4,4,4};
    cout << test.containsPattern(eg1,1,3) << endl;
    vector<int> eg2 = {1,2,1,2,1,1,1,1,3};
    cout << test.containsPattern(eg2,2,2) << endl;
    vector<int> eg3 = {1,2,1,2,1,3};
    cout << test.containsPattern(eg3,2,3) << endl;
    vector<int> eg4 = {1,2,3,1,2};
    cout << test.containsPattern(eg3,2,2) << endl;
}
//
// Created by ASUS on 2023/9/11.
//
