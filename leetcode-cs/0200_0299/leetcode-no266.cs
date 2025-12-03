// problem: https://leetcode.cn/problems/palindrome-permutation/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo266;

using System;

public class Solution {
    public bool CanPermutePalindrome(string s) {
        var cnt = new int[26];
        for (var i = 0; i < s.Length; ++i) {
            cnt[s[i] - 'a']++;
        }

        var oneCnt = 0;
        for (var i = 0; i < 26; ++i) {
            if ((cnt[i] & 1) == 1) {
                oneCnt++;
            }
        }


        return oneCnt <= 1;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CanPermutePalindrome("carerac"));
        Console.WriteLine(s.CanPermutePalindrome("cartrac"));
        Console.WriteLine(s.CanPermutePalindrome("cartcac"));
        Console.WriteLine(s.CanPermutePalindrome("aab"));
        Console.WriteLine(s.CanPermutePalindrome("code"));
    }
}

//
// Created By ASUS At 12/2/2025 17:12:31
//