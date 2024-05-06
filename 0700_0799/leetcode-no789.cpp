#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = abs(target[0]) + abs(target[1]);
        for (auto ghost : ghosts){
            if (abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= abs(distance)){
                return false;
            }
        }
        return true;
    }
};
int main(){
    vector<vector<int>> data = {{1,0},{0,3}};
    vector<int> target = {0,1};
    Solution test;
    cout << test.escapeGhosts(data,target) << endl;

}
//
// Created by ASUS on 2023/5/23.
//
