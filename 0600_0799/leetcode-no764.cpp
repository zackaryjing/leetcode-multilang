#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> row_max(n,vector<int>(n,1));
        for (auto k : mines) {
            row_max[k[0]][k[1]] = 0;
        }
        cout << "test" << endl;
        for (int i = 0;i < n;++i){
            int tmp = 0;
            for (int j = 0;j < n;++j){
                cout << i << " " << j << endl;
                tmp ++;
                if (mines[i][j] != 0){
                    row_max[i][j] = tmp;
                } else {
                    tmp = 0;
                }
            }
        }
        cout << "here" << endl;
        for (auto j : row_max){
            for (auto i : j) {
                cout << i << " " ;
            }
            cout << endl;
        }
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{4,2}};
    test.orderOfLargestPlusSign(5,eg1);
}
//
// Created by ASUS on 2023/9/9.
//
