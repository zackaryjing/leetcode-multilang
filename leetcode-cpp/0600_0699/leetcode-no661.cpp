#include <iostream>

#include <vector>

using namespace std;

class Solution2 {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for (int i = 0;i < n;i++){
            if (i == 0){
                for (int j = 1;j < m;j++){
                    img[i][j] += img[i][j-1];
                }
            } else {
                img[i][0] += img[i-1][0];
                for (int j = 1;j < m;j++){
                    img[i][j] = img[i][j] + img[i-1][j] + img[i][j-1] - img[i-1][j-1];
                }
            }

        }

        for (int i = 0;i < n;i++){
            for (int j = 0;j< m;j++){
                cout << img[i][j] << " " ;
            }
            cout << endl;
        }
        for (int i = 1;i < n - 1;i++){
            for (int j = 1;j< m - 1;j++){
                if (j == 1){
                    ans[i][j] = img[i+1][j+1] - img[i+1][j-2];
                } else {
                    ans[i][j] = img[i+1][j+1] - img[i+1][j-2];
                }
            }
        }
    }
};

class Solution3 {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for (int i = 0;i<n;i++){
            int total = 0;
            for (int j : {0,1}){
                for (int k : {i-1,i,i+1}){
                    total += img[i][j];
                }
            }
            ans[i][0] = total / 6;
            for (int j : {m-1,m-2}){
                for (int k : {i-1,i,i+1}){
                    total += img[i][j];
                }
            }
            ans[i][m] = total / 6;
        }
        for (int i = 1;i < n - 1;i++){
            for (int j = 1;j < m - 1;j++){
                int total = 0;
                for (int t = i - 1;t <= i + 1;t++){
                    for (int k = j - 1;k <= j + 1;k++){
                        total += img[i][j];
                    }
                }
                ans[i][j] = total / 9;
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
//        cout << "here" << endl;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                int total = 0,cnt = 0;
//                cout << i << " " << j << endl;
                for (int t = i - 1;t <= i + 1;t++){
                    for (int k = j - 1;k <= j + 1;k++){
                        if (t < n and t >= 0 and k >= 0 and k < m){
                            cnt ++;
                            total += img[t][k];
//                            cout << i << " " << j << " " << t << " " << k << endl;
                        }
                    }
                }
                ans[i][j] = total / cnt;
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{100,200,100},{200,50,200},{100,200,100}};
    int n = eg1.size(),m = eg1[0].size();
    vector<vector<int>> res = test.imageSmoother(eg1);
    for (int i = 0;i < n;i++){
        for (int j = 0;j< m;j++){
            cout << res[i][j] << " " ;
        }
        cout << endl;
    }

}

//
// Created by ASUS on 2023/7/10.
//
