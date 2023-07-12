#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> isOne;
//        vector<vector<int>> vis(n,vector<int>(m));
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (grid[i][j] == 1){
                    isOne.push_back({i,j});
                }
            }
        }
//        for (auto t : isOne){
//            cout << t[0] << " " << t[1] << endl;
//        }
//        cout << string(30,'=') << endl;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int ans = 0;
        while (!isOne.empty()){
            vector<int> worsen;
//            for (auto t : isOne){
//                cout << t[0] << " " << t[1] << endl;
//            }
            for (int t = 0;t < isOne.size();t++){
                vector<int> each = isOne[t];
                for (auto direction : directions){
                    int ni = each[0] + direction[0],nj = each[1] + direction[1];
                    if (0 <= ni and ni < n and 0 <= nj and nj < m){
                        if (grid[ni][nj] == 2){
                            worsen.push_back(t);
                            break;
                        }
                    }
                }
            }
            reverse(worsen.begin(),worsen.end());
            if (worsen.empty() and not isOne.empty()){
                return -1;
            }
            for (auto index : worsen){
//                cout << isOne[index][0] << " " << isOne[index][1] << endl;
                grid[isOne[index][0]][isOne[index][1]] = 2;
                isOne.erase(isOne.begin() + index);
            }
//            cout << string(30,'-') << endl;
            ans ++;
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << test.orangesRotting(eg1) << endl;
    vector<vector<int>> eg2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << test.orangesRotting(eg2) << endl;
}

//
// Created by ASUS on 2023/7/10.
//
