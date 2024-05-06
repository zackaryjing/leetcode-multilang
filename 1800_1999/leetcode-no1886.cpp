#include <iostream>
#include <vector>
using namespace std;

void drawmatrix(vector<vector<int>>& data){
    cout << string(20,'-') << endl;
    int n = data.size();
    int m = data[0].size();
    for (int i = 0;i < n;++i){
        for (int j = 0;j < m;++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << string(20,'-') << endl;
}

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(),midi = n/2,midj = (n + 1) / 2;
//        drawmatrix(mat);
//        cout << midi << " " << midj << endl;
        if (mat == target) return true;
        for (int t = 0;t < 3;++t){
            for (int i = 0;i < midi;i++){
                for (int j = 0;j < midj;j++){
                    swap(mat[i][j],mat[j][n - i - 1]);
                    swap(mat[i][j],mat[n - i - 1][n - j - 1]);
                    swap(mat[i][j],mat[n - j - 1][i]);
                }
            }
            if (mat == target) return true;
//            drawmatrix(mat);
        }
        return false;
    }
};



int main(){
    Solution test;
    vector<vector<int>> mat3 = {{1,1},{0,1}};
    vector<vector<int>> tar3 = {{1,1},{1,0}};
    cout << test.findRotation(mat3,tar3) << endl;
    vector<vector<int>> mat1 = {{0,1},{1,0}};
    vector<vector<int>> test1 = {{0,1},{1,0}};
//    cout << (mat1 == test1) << endl;
    vector<vector<int>> tar1 = {{1,0},{0,1}} ;
    cout << test.findRotation(mat1,tar1) << endl;
    vector<vector<int>> mat2 = {{0,1},{1,0}};
    vector<vector<int>> tar2 = {{1,0},{0,1}} ;
    cout << test.findRotation(mat2,tar2) << endl;
}
//
// Created by ASUS on 2023/8/13.
//
