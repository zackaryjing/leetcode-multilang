#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>> directions = {{'N', make_pair(1,0)},
                                                        {'E', make_pair(0,1)},
                                                        {'S', make_pair(-1,0)},
                                                        {'W', make_pair(0,-1)}};
        set<pair<int,int>> vis;
        vis.insert(make_pair(0,0));
        int startx = 0,starty = 0;
        for (auto each : path){
            startx += directions[each].first;
            starty += directions[each].second;
            pair<int,int> tmp = make_pair(startx,starty);
            if (vis.find(tmp) != vis.end()){
                return true;
            }
            vis.insert(tmp);
        }
        return false;
    }
};
int main(){
    Solution test;
    cout << test.isPathCrossing("NES") << endl;
}

//
// Created by ASUS on 2023/7/11.
//
