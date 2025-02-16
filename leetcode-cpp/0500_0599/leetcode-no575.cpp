#include <iostream>
#include <set>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        set<int> types(candyType.begin(), candyType.end()); // TODO: 改进建议 使用bitset。
        return min(types.size(), candyType.size() / 2);
    }
};

int main() {
    Solution test;
    cout << test.distributeCandies(*make_unique<vector<int> >(vector{1, 1, 2, 2, 3, 3})) << endl;;
    cout << test.distributeCandies(*make_unique<vector<int> >(vector{1, 1, 2, 3})) << endl;;
    cout << test.distributeCandies(*make_unique<vector<int> >(vector{6, 6, 6, 6})) << endl;;
}


//
// Created by ASUS on 2025/2/7.
//
