// problem: https://leetcode.cn/problems/strobogrammatic-number/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo246;

using System;

public class Solution {
    public bool IsStrobogrammatic(string num) {
        int n = num.Length;
        for (int i = 0; i <= n / 2; ++i) {
            var first = num[i];
            var second = num[n - 1 - i];
            if (first == '6' && second == '9' ||
                first == '9' && second == '6' ||
                first == '1' && second == '1' ||
                first == '0' && second == '0' ||
                first == '8' && second == '8') {
                continue;
            }

            return false;
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
    }
}

//
// Created By jing At 11/30/25 17:11:28
//