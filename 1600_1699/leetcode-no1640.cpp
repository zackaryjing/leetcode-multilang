#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        unordered_map<int, vector<int>> auxiliary;
        int pos = 0, arrLength = arr.size(), piecesLength = 0;
        for (auto piece: pieces) {
            auxiliary[piece[0]] = piece;
            piecesLength += piece.size();
        }
        if (piecesLength != arr.size()) {
            return false;
        }
        for (auto [k,v] : auxiliary) {
//            cout << k << ": ";
            for (auto t : v) {
//                cout << t << "," ;
            }
//            cout << endl;
        }
        while (true) {
//            cout << "pos: " << pos << endl;
            if (pos >= arrLength) {
                if (pos == piecesLength) {
                    return true;
                } else {
                    return false;
                }
            }
            vector<int> correspond;
            correspond = auxiliary[arr[pos]];
            if (correspond.empty()) {
                return false;
            } else {
                int i = 1;
                for (; i < correspond.size(); ++i) {
                    if (correspond[i] != arr[pos + i]) {
                        return false;
                    }
                }
                pos = pos + i;
            }
        }
    }
};

int main() {
    Solution test;
    vector<int> arr1 = {15, 88};
    vector<vector<int>> pieces1 = {{88},
                                   {15}};
    cout << test.canFormArray(arr1, pieces1) << endl;
    vector<int> arr2 = {49,18,16};
    vector<vector<int>> pieces2 = {{16,18,49}};
    cout << test.canFormArray(arr2, pieces2) << endl;
    vector<int> arr3 = {91,4,64,78};
    vector<vector<int>> pieces3 = {{78},{4,64},{91}};
    cout << test.canFormArray(arr3, pieces3) << endl;
}
//
// Created by ASUS on 2024/8/3.
//
