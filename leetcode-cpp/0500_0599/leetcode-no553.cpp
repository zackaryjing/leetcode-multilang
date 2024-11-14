#include <iostream>
#include <vector>

using namespace std;

struct Data {
    double max_val;
    double min_val;
    string max_str;
    string min_str;
//    Data(): max_val(10000.0),min_val(0.0) {};
    Data(){
        this->min_val=10000.0;
        this->max_val=0.0;
    }
};

class Solution {
private:
    double ans;
public:
    string optimalDivision(vector<int> &nums) {
        int n = nums.size();
        cout << "n:" << n << endl;
        vector<vector<Data>> dp(n, vector<Data>(n));
        cout << dp.size() << endl;
        for (int j = 0; j < n; ++j) {
            dp[j][j].min_val = nums[j];
            dp[j][j].max_val = nums[j];
            dp[j][j].min_str = to_string(nums[j]);
            dp[j][j].max_str = to_string(nums[j]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + i < n; ++j) {
                for (int k = j; k < j + i; ++k) {
                    if (dp[j][j + i].max_val < dp[j][k].max_val / dp[k + 1][j + i].min_val) {
                        dp[j][j + i].max_val = dp[j][k].max_val / dp[k + 1][j + i].min_val;
                        cout << dp[j][j+i].max_val << endl;
                        if (k + 1 == j + i) {
                            dp[j][j + i].max_str = dp[j][k].max_str + "/" + dp[k + 1][j + i].min_str;
                        } else {
                            dp[j][j + i].max_str = dp[j][k].max_str + "/(" + dp[k + 1][j + i].min_str + ")";
                        }
                    }
                    if (dp[j][j + i].min_val > dp[j][k].min_val / dp[k + 1][j + i].max_val) {
                        dp[j][j + i].min_val = dp[j][k].min_val / dp[k + 1][j + i].max_val;
                        if (k + 1 == j + i) {
                            dp[j][j + i].min_str = dp[j][k].min_str + "/" + dp[k + 1][j + i].max_str;
                        } else {
                            dp[j][j + i].min_str = dp[j][k].min_str + "/(" + dp[k + 1][j + i].max_str + ")";
                        }
                    }
                }
            }
        }
        return dp[0][n - 1].max_str;
    }
};


int main() {
    Solution test;
    vector<int> nums1 = {1000,100,10,2};
    cout << test.optimalDivision(nums1) << endl;

}
//
// Created by ASUS on 2024/2/29.
//
