// problem:  https://leetcode.cn/problems/maximum-binary-string-after-change/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    string maximumBinaryString(string binary) {
        int onecnt = 0, n = binary.size();
        for (const char &c: binary) onecnt += c == '1';
        return onecnt == n ? string(onecnt, '1')
                           : (onecnt != 0 ? string(n - onecnt - 1, '1') + '0' + string(onecnt, '1') : string(n, '0'));
    }
};


class Solution3 {
public:
    string maximumBinaryString(string binary) {
        int onecnt = 0, n = binary.size();
        for (const char &c: binary) onecnt += c == '1';
        if (onecnt == n) {
            return string(onecnt, '1');
        }
        if (onecnt == 0) {
            return string(n - 1, '1') + "0";
        }
        int preOneCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (binary[i] != '1') break;
            preOneCnt++;
        }
        return string(preOneCnt + (n - onecnt - 1), '1') + '0' + string(onecnt - preOneCnt, '1');
        // string res;
        // res.reserve(n);
        // res.append(string(preOneCnt + (n - onecnt - 1), '1'));
        // res.push_back('0');
        // res.append(string(onecnt - preOneCnt, '1'));
        // return res;
    }
};


class Solution {
public:
    string maximumBinaryString(string binary) {
        int onecnt = 0; const int n = binary.size();
        string res(n, '0');
        for (const char &c: binary) onecnt += c == '1';
        if (onecnt == n) {
            ranges::fill(res, '1');
        } else if (onecnt == 0) {
            ranges::fill_n(res.begin(), n - 1, '1');
        } else {
            int preOneCnt = 0;
            for (int i = 0; i < n; ++i) {
                if (binary[i] != '1') break;
                preOneCnt++;
            }
            ranges::fill_n(res.begin(), preOneCnt + n - onecnt - 1, '1');
            ranges::fill_n(res.begin() + preOneCnt + n - onecnt, onecnt - preOneCnt, '1');
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maximumBinaryString("000110") << "\n111011e" << endl << endl;
    cout << test.maximumBinaryString("01") << "\n01e" << endl << endl;
    cout << test.maximumBinaryString("11") << "\n11e" << endl << endl;
    cout << test.maximumBinaryString("00") << "\n10e" << endl << endl;
    cout << test.maximumBinaryString("1100") << "\n1110e" << endl << endl;
}

//
// Created By jing At 2026-06-04 15:47
//
