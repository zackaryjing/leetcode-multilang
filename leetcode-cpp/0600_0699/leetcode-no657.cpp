#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> cnts;
        int h = 0;
        int v = 0;
        for (const auto& ch: moves) {
            switch (ch) {
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
                case 'R':
                    h++;
                    break;
                case 'L':
                    h--;
                    break;
            }
        }
        return h == 0 and v == 0;
    }
};

class Solution2 {
public:
    bool judgeCircle(string moves) {
        map<char, int> cnts;
        for (auto ch: moves) {
            cnts[ch]++;
        }
        return cnts['U'] == cnts['D'] and cnts['L'] == cnts['R'];
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.judgeCircle("UD") << endl;
    cout << test.judgeCircle("LL") << endl;
}


//
// Created by ASUS on 2025/2/17.
//
