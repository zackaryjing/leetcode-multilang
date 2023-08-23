#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;

// 构建用于 KMP 算法的 Next 数组
std::vector<int> buildNext(const std::string& pattern) {
    int n = pattern.length();
    std::vector<int> next(n, 0);

    int i = 1, j = 0;
    while (i < n) {
        if (pattern[i] == pattern[j]) {
            next[i++] = ++j;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                next[i++] = 0;
            }
        }
    }

    return next;
}

// 获取两个字符串的前缀和后缀的最长公共部分长度
int getLongestCommonLength2(const std::string& str1, const std::string& str2) {
    std::string combinedStr = str1 + "#" + str2;
    int m = str1.length();
    int n = combinedStr.length();

    std::vector<int> next = buildNext(combinedStr);
    int longestCommonLength = next[n - 1];

    // 进一步检查最长公共部分是否为 str1 的后缀
    int suffixStartIndex = m - longestCommonLength;
    std::string suffix = str1.substr(suffixStartIndex);
    if (suffix == str2.substr(0, longestCommonLength)) {
        return longestCommonLength;
    } else {
        return 0;
    }
}



class Solution3 {
public:
    int minimumString(string a, string b, string c) {
        int total = a.size() + b.size() + c.size();
        vector<vector<string>> tmp = {{a,b},{b,a},{a,c},{c,a},{c,b},{b,c}};
        for (auto i : tmp) cout << i[0] << " " << i[1] << " | ";
        cout << endl;
        vector<int> data(6);
        int i = 0;
        for (auto& each : tmp){
            data[i] = getLongestCommonLength2(each[0],each[1]);
            i++;
        }
        for (auto j : data) cout << j << " | ";
        cout << endl;
        int minn = INT_MAX;
        vector<vector<int>> order = {{0,5},{4,1},{1,2},{3,0},{5,3},{2,4}};
        int t = 0,mint = 0;
        for (t = 0 ;t < order.size();t++){
            auto each = order[t];
            if (total - data[each[0]] - data[each[1]] < minn){
                minn = total - data[each[0]] - data[each[1]];
                mint = t;
            }
        }
        string ans;
        return 9;
    }
};

int getcoml(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // 构建动态规划表
    int dp[m + 1][n + 1];
    memset(dp,0,sizeof(int)*(m + 1)*(n + 1));
    int longestLength = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                longestLength = std::max(longestLength, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return longestLength;
}


class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> src = {std::move(a),std::move(b),std::move(c)};
        vector<vector<int>> order = {{0,1,2},
                                     {0,2,1},
                                     {1,2,0},
                                     {1,0,2},
                                     {2,1,0},
                                     {2,0,1}};
        int minLength = INT_MAX,totalLength = src[0].length() + src[1].length() + src[2].length(),pos = 0;
        set<string> candidate;
        for (int j = 0;j < order.size();j++){
            vector<int>each = order[j];
            int cur = (totalLength - getcoml(src[each[0]],src[each[1]]) - getcoml(src[each[1]],src[each[2]]));
            if (cur < minLength){
                candidate.clear();
                minLength = totalLength - getcoml(src[each[0]],src[each[1]]) - getcoml(src[each[1]],src[each[2]]);
                string s1 = src[order[j][0]],s2 = src[order[j][1]], s3 =src[order[j][2]];
                int first =getcoml(s1,s2);
                int second =getcoml(s2,s3);
                string ans;
                ans += s1 + s2.substr(first,s2.size() - first);
                ans += s3.substr(second,s3.size() - second);
                candidate.insert(ans);
            } else if (cur == minLength){
                string s1 = src[order[j][0]],s2 = src[order[j][1]], s3 =src[order[j][2]];
                int first =getcoml(s1,s2);
                int second =getcoml(s2,s3);
                string ans;
                ans += s1 + s2.substr(first,s2.size() - first);
                ans += s3.substr(second,s3.size() - second);
                candidate.insert(ans);
            }
        }
//        for (auto x : candidate){
//            cout << x << " <-> " << endl;
//        }
        return *candidate.begin();
    }
};
//        vector<vector<int>> order = {{0,1,2},
//                                     {0,2,1},
//                                     {1,2,0},
//                                     {1,0,2},
//                                     {2,1,0},
//                                     {2,0,1}};
int main() {
    Solution test;
//    cout << getLongestCommonLength("abc","bca") << endl;
    cout << getcoml("xyyyz","xzyz") << endl;
    cout << test.minimumString("xyyyz", "xzyz", "zzz") << endl;
    cout << test.minimumString("abc", "bca", "aaa") << endl;
    cout << test.minimumString("ab", "ba", "aba") << endl;
}
//
// Created by ASUS on 2023/7/30.
//
