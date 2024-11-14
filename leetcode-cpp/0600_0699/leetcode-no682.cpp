#include <iostream>
#include <vector>
#include <numeric>
#include <string>>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &operations) {
        vector<int> stack;
        for (auto i: operations) {
            if (i == "C") {
//                cout << stack.back() << endl;
                stack.pop_back();
//                cout << stack.back() << endl;
//                cout << string(10,'-') << endl;
            } else if (i == "D") {
                int temp = stack.back();
                temp *= 2;
                // stack.pop_back();
                stack.push_back(temp);
            } else if (i == "+") {
                int temp1 = stack.back();
                int temp2 = *(++stack.rbegin());
//                cout << temp1 << " " << temp2 << " <- temp" << endl;
                stack.push_back(temp1 + temp2);
            } else {
                stack.push_back(stoi(i));
            }
        }
        int ans = 0;
//        for (auto i : stack){
//            cout << i << " ";
//        }
        return accumulate(stack.begin(), stack.end(), ans);
//        cout << ans << endl;
//        return ans;
    }
};

int main() {
    Solution test;
    vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    cout << test.calPoints(ops) << endl;
}
//
// Created by ASUS on 2024/2/23.
//
