#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        map<int,int> data;
        for (int i = 0;i < barcodes.size();i++){
            data[barcodes[i]] += 1;
        }
        multimap<int,int> newdata;
        for (const auto& each : data){
//            cout << each.first << "->" << each.second << endl;
            newdata.insert(make_pair(each.second,each.first));
        }
//        cout << string(30,'-') << endl;
//        for (const auto& each : newdata){
//            cout << each.first << "->" << each.second << endl;
//        }
        vector<int> ans(n);
        int pos = 0;
        for (auto it = newdata.rbegin();it != newdata.rend();++it){
            for (int j = 0;j < it->first;j++){
                ans[pos] = it->second;
                pos += 2;
                if (pos >= n){
                    pos = 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> eg1 = {1,1,1,1,2,2,3,3};
    vector<int> res = test.rearrangeBarcodes(eg1);
    for (auto show : res){
        cout << show << " ";
    }
    cout << endl;
}
//
// Created by ASUS on 2023/7/11.
//
