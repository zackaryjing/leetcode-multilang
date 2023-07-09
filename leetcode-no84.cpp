#include <iostream>
#include <vector>
#include <stack>
#include <utility>
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
        //for (auto i : rightsmall) cout << i << " " ;
        int max = 0;
        for (int j = 0;j < heights.size();j++){
            if (heights[j] * (rightsmall[j] - leftsmall[j] - 1) > max) {
                max = heights[j] * (rightsmall[j] - leftsmall[j] - 1);
            }
        }
        return max;
    }
};
int main(){
    Solution test;
    vector<int> eg1 = {6,7,5,2,4,5,9,3};
    cout << test.largestRectangleArea(eg1) << endl;
}
//
// Created by ASUS on 2023/7/8.
//
