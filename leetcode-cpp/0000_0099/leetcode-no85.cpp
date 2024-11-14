#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> heap({make_pair(-1,-1)});
        vector<int> leftsmall;
        for (int i = 0;i<heights.size();i++){
            while (heap.top().first >= heights[i]){
                heap.pop();
            }
            leftsmall.push_back(heap.top().second);
            heap.push({heights[i],i});
        }
        //for (auto i : leftsmall) cout << i << " " ;
        //cout << endl;
        stack<pair<int,int>> heap2({make_pair(-1,heights.size())});
        vector<int> rightsmall;
        for (int i = (heights.size() - 1);i>=0;i--){
            while (heap2.top().first >= heights[i]){
                heap2.pop();
            }
            rightsmall.push_back(heap2.top().second);
            heap2.push({heights[i],i});
        }
        reverse(rightsmall.begin(),rightsmall.end());
//        for (auto i : rightsmall) cout << i << " " ;
        int max = 0;
        for (int j = 0;j < heights.size();j++){
            if (heights[j] * (rightsmall[j] - leftsmall[j] - 1) > max) {
                max = heights[j] * (rightsmall[j] - leftsmall[j] - 1);
            }
        }
        return max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        //vector<vector<int>> preSum(n,vector<int>(m));
        vector<int> preSum(m);
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (matrix[i][j] != '0'){
                    preSum[j] += (matrix[i][j] - '0');
                } else {
                    preSum[j] = 0;
                }
            }
//            for (auto i : preSum) cout << i << " " ;
//            cout << endl;
            int tmp = largestRectangleArea(preSum);
            if (tmp > ans){
                ans = tmp;
            }
        }
        return ans;
    }
};


int main(){
//    Solution test;
//    vector<vector<char>> eg1 = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
//    cout << test.maximalRectangle(eg1) << endl;
//    vector<vector<char>> eg2 = {{'1','0'},{'0','1'}};
//    cout << test.maximalRectangle(eg2) << endl;
printf("%c",1);
}
//
// Created by ASUS on 2023/6/16.
//
