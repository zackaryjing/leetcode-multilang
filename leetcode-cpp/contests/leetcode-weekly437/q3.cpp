#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
    // 比赛完了才写出来，哎
public:
    bool maxSubstringLength(string s, int k) {
        if (k == 0) {
            if (s.empty()) {
                return false;
            } else {
                return true;
            }
        }
        if (s.size() < k) {
            return false;
        }
        int n = s.size();
        map<char, int> end_pos;
        map<char, int> start_pos;
        vector<char> all_char;
        for (int i = 0; i < n; i++) {
            end_pos[s[i]] = i;
            if (find(all_char.begin(), all_char.end(), s[i]) == all_char.end()) {
                start_pos[s[i]] = i;
                all_char.push_back(s[i]);
            }
        }
        set<char> vis;
        map<int, int> valid_segment;
        for (auto ch: all_char) {
            int i = start_pos[ch];
            int end = end_pos[ch];
            bool valid = true;
            while (i <= end) {
                if (vis.find(s[i]) != vis.end()) {
                    valid = false;
                    break;
                }
                end = max(end, end_pos[s[i]]);
                i++;
            }
            if (valid) {
                valid_segment[end] = start_pos[ch];
            }
            vis.insert(ch);
        }
        vector<int> dp(n);
        if (valid_segment.count(0)) {
            dp[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (valid_segment.count(i)) {
                if (valid_segment[i] != 0) {
                    dp[i] = max(dp[i - 1], dp[valid_segment[i] - 1] + 1);
                } else {
                    dp[i] = max(dp[i - 1], 1);
                }
            } else {
                dp[i] = dp[i - 1];
            }
        }
        if (k == 1 and valid_segment.size() == 1) {
            return false;
        }
        return dp[n - 1] >= k;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxSubstringLength(
        "nbuirvanjiccnsyyyoirleqsrwrvxepaglcidqplyryujytzqoncxjgwdmatytgwhzyhlsodrbzrpbbitovtdasazjtoyyfhowqqrzuvjveydceouscrfazzoblqhalhfybwheybkpcroijxvarrtqrqnmwslkpdducfeblvfecyjyulxgahxlzlyztssfzwvfujrriryslkvdwhmkcyebfhkadrahunvxivkwitilyzknwyujtylahgmlddymlbrbrniomepbmdieasuvdcqnzfwspxewbbpruxrznjxwnjjxvblxyrgv",
        1) << endl << string(30, '-') << endl;
    cout << test.maxSubstringLength("wyafxgsyzfdyciynklf", 10) << endl << string(30, '-') << endl;
    cout << test.maxSubstringLength("abcdbaefab", 2) << endl << string(30, '-') << endl;
    cout << test.maxSubstringLength("cdefdc", 3) << endl << string(30, '-') << endl;;
    cout << test.maxSubstringLength("cji", 3) << endl << string(30, '-') << endl;;
    cout << test.maxSubstringLength("abeabe", 0) << endl << string(30, '-') << endl;
}


//
// Created by ASUS on 2025/2/16.
//
