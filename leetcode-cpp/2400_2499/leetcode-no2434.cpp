// problem:
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <ranges>
#include <stack>
#include <unordered_set>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;


class Solution {
    // Shouldn't use monotonic stack, and this is not a no aftereffect problem.
public:
    string robotWithString(string s) {
        vector<int> cnt(26);
        for (auto ch: s) {
            cnt[ch - 'a']++;
        }
        int n = s.size();
        vector<char> stack;
        string res;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            stack.push_back(ch);
            cnt[ch - 'a']--;
            char minChar;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] != 0) {
                    minChar = 'a' + j;
                    break;
                }
            }
            while (not stack.empty() and stack.back() <= minChar) {
                res.push_back(stack.back());
                stack.pop_back();
            }
        }
        while (not stack.empty()) {
            res.push_back(stack.back());
            stack.pop_back();
        }
        return res;
    }
};


class Solution2 {
    // [Fail] I just don't want to spend more time on this.
public:
    string getStackContent(vector<pair<char, int>> stk) {
        string res;
        for (auto [k,v]: stk) {
            res += k;
        }
        return res;
    }

    string robotWithString(string s) {
        int n = s.size();
        vector stack = {pair(s[0], 0)};
        priority_queue<int> backup;
        unordered_set inStack = {0};

        for (int i = 1; i < n; ++i) {
            cout << getStackContent(stack) << endl;
            if (stack.back().first >= s[i]) {
                while (not stack.empty() and stack.back().first > s[i]) {
                    inStack.erase(stack.back().second);
                    backup.push(stack.back().second);
                    stack.pop_back();
                }
            } else {
                while (not backup.empty() and s[backup.top()] <= s[i]) {
                    stack.emplace_back(s[backup.top()], backup.top());
                    inStack.insert(backup.top());
                    backup.pop();
                }
            }
            stack.emplace_back(s[i], i);
            inStack.insert(i);
        }

        string res;
        res.reserve(n);
        for (const auto [ch,_]: stack) {
            res.push_back(ch);
        }
        while (not backup.empty()) {
            res.push_back(s[backup.top()]);
            backup.pop();
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.robotWithString("lmimcysndjbhvsf") << "\nbfsvhjdnsycmiml" << endl;
    cout << test.robotWithString("mmuqezwmomeplrtskz") << "\neekstrlpmomwzqummz" << endl;
    cout << test.robotWithString("vzhofnpo") << "\nfnohopzv" << endl;
    cout << test.robotWithString("bydizfve") << "\nbdevfziy" << endl;
    cout << test.robotWithString("zza") << "\nazz" << endl;
    cout << test.robotWithString("bdda") << "\naddb" << endl;
    cout << test.robotWithString("bac") << "\nabc" << endl;
    cout << test.robotWithString("bcaddeca") << "\naaceddcb" << endl;
}

//
// Created By Zackary At 2025-06-06 14:30:32
//
