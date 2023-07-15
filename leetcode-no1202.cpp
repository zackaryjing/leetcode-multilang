#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> parent;
    map<int,int> cache;
    int withcache = 0;
    int tofind(int index){
        if (withcache){
            if (cache.find(index) == cache.end()){
                if (parent[index] != index) {
                    parent[index] = tofind(parent[index]);
                    cache[index] = parent[index];
                    return parent[index];
                }
            } else {
                return cache[index];
            }
        } else {
            if (parent[index] != index){
                parent[index] = tofind(parent[index]);
            }
        }
        return parent[index];
    }
    void uni(int index1,int index2){
        parent[tofind(index1)] = tofind(index2);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for (int i = 0;i < n;i++) parent.push_back(i);
        for (auto each : pairs) {
            if (tofind(each[0]) != tofind(each[1])){
                uni(each[0],each[1]);
            }
        }
        map<int,vector<int>> pos;
        withcache = 1;
        for (int t = 0;t < n;t++){
            parent[t] = tofind(t);
            pos[parent[t]].push_back(t);

        }
        for (auto& k : pos){
            vector<char> tmp;
            for (int h : k.second){
                tmp.push_back(s[h]);
            }
            sort(tmp.begin(),tmp.end());
            int pos = 0;
            for (int h : k.second){
                s[h] = tmp[pos++];
            }
        }
        return s;
    }
};

int main(){
    Solution test;
    string eg11 = "dcab";
    vector<vector<int>> eg12 = {{0,3},{1,2}};
    cout << test.smallestStringWithSwaps(eg11,eg12) << endl;
    Solution test2;
    string eg21 = "dcab";
    vector<vector<int>> eg22 = {{0,3},{1,2},{0,2}};
    cout << test2.smallestStringWithSwaps(eg21,eg22) << endl;
    Solution test3;
    string eg31 = "cba";
    vector<vector<int>> eg32 = {{0,1},{1,2}};
    cout << test3.smallestStringWithSwaps(eg31,eg32) << endl;

}
//
// Created by ASUS on 2023/7/12.
//
