#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[2] <= rec2[0] or rec1[0] >= rec2[2] or rec2[1] >= rec1[3] or rec2[3] <= rec1[1]){
            return false;
        }
        return true;
    }
};

int main(){
    Solution test;
    vector<int> temp1 = {0,0,2,2};
    vector<int> temp2 = {1,1,3,3};
    vector<int> temp3 = {0,0,1,1};
    vector<int> temp4 = {1,0,2,1};
    cout << test.isRectangleOverlap(temp1,temp2) << endl;
    cout << test.isRectangleOverlap(temp3,temp4) << endl;
    // if (test.isRectangleOverlap(temp1,temp2)) cout << "TRUE" << endl;
    // else cout << "FALSE" << endl;
}
//
// Created by ASUS on 2023/6/22.
//
