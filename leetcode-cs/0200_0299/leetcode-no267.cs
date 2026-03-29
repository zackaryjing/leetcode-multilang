// problem: https://leetcode.cn/problems/palindrome-permutation-ii/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Text;

namespace leetcodeNo267;

using System;

public class Solution {
    private int n;
    private char[] cand;
    private char[] cur;
    private readonly List<string> res = [];

    public IList<string> GeneratePalindromes(string s) {
        var cnt = new int[26];
        for (var i = 0; i < s.Length; ++i) {
            cnt[s[i] - 'a']++;
        }

        n = s.Length;
        cand = new char[n / 2];
        cur = new char[n];
        int pos = 0, oneCnt = 0;
        for (var i = 0; i < 26; ++i) {
            if ((cnt[i] & 1) == 1) {
                oneCnt++;
                cur[n / 2] = (char)('a' + i);
            }

            for (var j = 0; j < cnt[i] / 2; ++j)
                cand[pos++] = (char)('a' + i);
        }

        if (oneCnt > 1) return [];
        Dfs(0, (n + 1) / 2);
        return res;
    }

    private void Dfs(int avl, int pos) {
        var last = ' ';
        var found = false;
        for (var i = 0; i < n / 2; ++i) {
            if (((avl >> i) & 1) == 0) {
                found = true;
                if (cand[i] != last) {
                    cur[pos] = cand[i];
                    cur[n - pos - 1] = cand[i];
                    Dfs(avl | (1 << i), pos + 1);
                    last = cand[i];
                }
            }
        }

        if (!found) {
            res.Add(new string(cur));
        }
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(string.Join(",", s.GeneratePalindromes("aabb")));
        // Console.WriteLine(string.Join(",", s.GeneratePalindromes("abc")));
        Console.WriteLine(string.Join(",", s.GeneratePalindromes("abeaeeb")));
    }
}

//
// Created By ASUS At 12/2/2025 17:12:26
//