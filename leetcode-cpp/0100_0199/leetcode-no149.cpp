#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int getgcd(int x,int y){
        while (y != 0){
            int tmp = x;
            x = y;
            y = tmp % y;
        }
        return x;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ret = 0;
        for (int i = 0;i < n;i++){
            if (ret > n/2 || ret >= n - i){
                break;
            }
            map<int,int> mp;
            for (int j = i + 1;j < n;j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int mx,my;
                if (dx == 0){
                    dx = 0;
                    dy = 1;
                } else {
                    if (dy == 0){
                        dx = 1;
                        dy = 0;
                    } else if (dy < 0){
                        dy = -dy;
                        dx = -dx;
                    }
                }
                int cd = getgcd(dx,dy);
                dx /= cd;
                dy /= cd;
                mp[dx+dy*20001]++;
            }
            int maxn = 0;
            for (auto [_,num] : mp){
                maxn = max(maxn,num + 1);
            }
            ret = max(maxn,ret);
        }
        return ret;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << test.maxPoints(eg1) << endl;

}
//
// Created by ASUS on 2023/7/28.
//
