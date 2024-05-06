#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(),deadends.end(),"0000") != deadends.end()){
            return -1;
        }
        if (target == "0000"){
            return 0;
        }
        unordered_set<string> forbid(deadends.begin(),deadends.end());
        queue<string> search;
        search.push("0000");
        // unordered_set<string> vis;
        unordered_map<string,int> vis;
        vis["0000"] = 0;
        int minstep = INT_MAX;
        while (!search.empty()){
            string cur = search.front();
            // cout << cur << endl;
            int step = vis[cur];
            search.pop();
            for (auto j : {1,9}){
                for (int i = 0;i < 4;i++){
                    string nxt = cur;
                    nxt[i] = (char)((nxt[i] - '0' + j) % 10 + '0');
                    if (vis.find(nxt) == vis.end() and (forbid.find(nxt) == forbid.end())) {
                    //if (vis.find(nxt) == vis.end() && (find(deadends.begin(), deadends.end(),nxt) == deadends.end())) {
                        // cout << nxt << " " << step + 1 << endl;
                        if (nxt == target && (step + 1) < minstep) {
                            // cout << nxt << " *** " << endl;
                            minstep = step + 1;
                        }
                        search.push(nxt);
                        vis[nxt] = step + 1;
                    }

                }
            }
        }
        return (minstep != INT_MAX) ? minstep : -1;
    }
};

int main(){
    Solution test;
    vector<string> dead = {"0201","0101","0102","1212","2002"};
    cout << test.openLock(dead,"0202") << endl;

}
//
// Created by ASUS on 2023/6/20.
//
