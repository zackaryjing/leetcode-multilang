#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        set<char> vis;
        vector<pair<int,char>> pos;
        for (int i = 0;i < s.size();++i){
            if (vis.find(s[i]) == vis.end()){
                vis.insert(s[i]);
                pos.emplace_back(i,s[i]);
            }
        }
        vis.clear();
        for (int i = s.size() - 1;i >= 0;--i){
            if (vis.find(s[i]) == vis.end()){
                vis.insert(s[i]);
                pos.emplace_back(i,s[i]);
            }
        }
        set<char> show;
        vector<int> ans;
        int start = 0;
        sort(pos.begin(), pos.end());
        for (auto k : pos){
            if (show.find(k.second) == show.end()){
                show.insert(k.second);
            } else if (show.find(k.second) != show.end()){
                if (show.size() == 1){
                    ans.push_back(k.first - start + 1);
                    start = k.first + 1;
                    show.clear();
                } else {
                    show.erase(k.second);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<int> res;
    res = test.partitionLabels("ababcbacadefegdehijhklij");
    for (auto t : res) cout << t << " ";
    cout << endl;
    res = test.partitionLabels("eccbbbbdec");
    for (auto t : res) cout << t << " ";
    cout << endl;
}
//
// Created by ASUS on 2023/9/6.
//
