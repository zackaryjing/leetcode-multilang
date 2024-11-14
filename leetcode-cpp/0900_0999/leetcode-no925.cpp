#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < name.size() and pos2 < typed.size()) {
//            cout << pos1 << ": " << pos2 << endl;
            int first = 0, second = 0;
            if (name[pos1] != typed[pos2]) return false;
            while (pos1 < name.size() - 1) {
                if (name[pos1] == name[pos1 + 1]) {
                    first++;
                    pos1++;
                } else {
                    break;
                }
            }
            while (pos2 < typed.size() - 1) {
                if (typed[pos2] == typed[pos2 + 1]) {
                    second++;
                    pos2++;
                } else {
                    break;
                }
            }
            if (second < first) {
                return false;
            }
            pos1++;
            pos2++;
        }
        if (pos2 != typed.size() or pos1 != name.size()) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution test;
    cout << test.isLongPressedName("aabbbccc", "aaabbbbcc") << endl; // 0
    cout << test.isLongPressedName("aabbbccc", "aaab") << endl; // 0
    cout << test.isLongPressedName("aabbbccc", "aaabbbdbccc") << endl; // 0
    cout << test.isLongPressedName("aabbbccc", "aaabbbbccdc") << endl; // 0
    cout << test.isLongPressedName("aabbbccc", "aaabbbbcccd") << endl; // 0
    cout << test.isLongPressedName("aabbbcccdd", "aaabbbbcccddd") << endl; // 1

}
//
// Created by ASUS on 2024/8/10.
//
