#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > largeGroupPositions(string s) {
        char current = ' ';
        int length = 0;
        int start_pos = 0;
        int i = 0;
        vector<vector<int> > ans;
        for (auto ch: s) {
            if (ch == current) {
                length++;
            } else {
                if (length > 2) {
                    ans.push_back({start_pos, i - 1});
                }
                current = ch;
                length = 1;
                start_pos = i;
            }
            i++;
        }
        if (length > 2) {
            ans.push_back({start_pos,i - 1});
        }
        return ans;
    }
};

int main() {
    Solution test;
    auto res = test.largeGroupPositions("aaa");
    for (auto pair: res) {
        cout << pair[0] << ", " << pair[1] << endl;
    }
}

//
// Created by ASUS on 2025/2/6.
//
