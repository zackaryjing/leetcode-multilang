#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
    // 官解，抄一遍是因为发现remain--这一步的位置不一样。研究发现是，不管这次的reamin[ch]--放在哪里都可以，
    // 因为只有在下一个循环体里面才会用到
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        for (char ch: s) {
            num[ch - 'a']++;
        }
        cout << num['c' - 'a'] << endl;

        string stk;
        for (char ch: s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};

class Solution3 {
public:
    string removeDuplicateLetters(string s) {
        set<char> inStack;
        vector<char> stack;
        map<char, int> remain;
        for (auto ch: s) {
            remain[ch]++;
        }
        for (auto ch: s) {
            remain[ch]--;
            if (inStack.find(ch) == inStack.end()) {
                while (not stack.empty() and ch < stack.back()) {
                    if (remain[stack.back()] > 0) {
                        inStack.erase(stack.back());
                        stack.pop_back();
                    } else {
                        break;
                    }
                }
                stack.push_back(ch);
                inStack.insert(ch);
            }
            // cout << string(stack.begin(), stack.end()) << endl;
        }
        return string(stack.begin(), stack.end());
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.removeDuplicateLetters("ca") << " <---" << endl; // abc
    cout << test.removeDuplicateLetters("abacb") << " <---" << endl; // abc
    cout << test.removeDuplicateLetters("cdadabcc") << " <---" << endl; // adbc
    cout << test.removeDuplicateLetters("bccab") << " <---" << endl; // bca
    cout << test.removeDuplicateLetters("ecbacba") << " <---" << endl; // eacb
    cout << test.removeDuplicateLetters("bcabc") << " <---" << endl; // abc
    cout << test.removeDuplicateLetters("cbacdcbc") << " <---" << endl; // acdb
}

class Solution2 {
    // 从算法上来说就错了。
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        map<char, vector<int> > pos;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            pos[ch].push_back(i);
        }
        string ans(n, ' ');
        set<char> unique;
        for (auto [k,val]: pos) {
            if (val.size() == 1) {
                ans[val[0]] = k;
                unique.insert(k);
                // cout << ans << endl;
            }
        }
        for (auto [k,val]: pos) {
            if (val.size() != 1) {
                // cout << "placing: " << k << endl;
                bool set_val = false;
                for (auto index: val) {
                    int i = index;
                    while (i < n - 1 and ans[i] == ' ') {
                        i++;
                    }
                    if (ans[i] == ' ') {
                        ans[index] = k;
                        set_val = true;
                        // cout << ans << endl;
                        break;
                    }
                    // 如果i == n - 1此时不知道 ans[i]还是不是' '，但是由于' '的ASCII码小于字母，所以也不会影响判断。
                    if (k < ans[i]) {
                        // 插入之后会使得字典序变小的第一个位置
                        ans[index] = k;
                        set_val = true;
                        // cout << ans << endl;
                        break;
                    }
                }
                if (not set_val) {
                    ans[val.back()] = k; // 找不到就放在最后
                    // cout << ans << endl;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i] == ' ') {
                ans.erase(i, 1);
            }
        }
        return ans;
    }
};


//
// Created by ASUS on 2025/2/16.
//
