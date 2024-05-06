#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string ans;
        for (int i = n - 1;i >= 0;--i){
            if (isdigit(s[i])) ans += (char)('a' + s[i] - '0' - 1);
//            else {
//                cout << (char)('a' + stoi((string)"" + s[i-2] + s[i-1]) - 1) << " <-> " << i << endl;
//                i -= 2;
//            }
            else if (s[i] == '#') {
                ans += (char)('a' + stoi((string)"" + s[i-2] + s[i-1]) - 1);
                i -= 2;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.freqAlphabets("10#11#12") << endl;
    cout << test.freqAlphabets("1326#") << endl;
}
//
// Created by ASUS on 2023/7/30.
//
