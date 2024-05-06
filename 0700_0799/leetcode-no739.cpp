#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        cout << "here 1" << endl;
        vector<vector<int>> stack = {};
        vector<int> ans(temperatures.size());
        for (int i = 0;i < temperatures.size();i++){
            int temperature = temperatures[i];
            if (stack.empty()) stack.push_back(vector<int> {temperature,i});
            else {
//                cout << "here 3" << endl;
                while ((!stack.empty()) && stack.back()[0] < temperature){
//                    cout << stack.back()[1] << endl;
                    ans[stack.back()[1]] = i - stack.back()[1];
                    stack.pop_back();
                }
                stack.push_back(vector<int> {temperature,i});
//                cout << "here 4" << endl;
            }
        }
//        cout << "here 2" << endl;
        if (!stack.empty()){
            for (auto each : stack){
                ans[each[1]] = 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
//    vector<int> te = {73,74,75,71,69,72,76,73};
    vector<int> te = {30,40,50,60};
    vector<int> res = test.dailyTemperatures(te);
    for (auto i : res){
        cout << i << " ";
    }
}







//
// Created by ASUS on 2023/5/24.
//
