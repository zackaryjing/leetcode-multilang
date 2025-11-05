// problem: https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections;
using System.Text;

namespace leetcodeNo1209;

using System;
using System.Collections.Generic;

public class Solution2 {
    public string RemoveDuplicates(string s, int k) {
        var n = s.Length;
        var cnts = new Stack<int>();
        var chrs = new Stack<char>();
        int curCnt = 1;
        char curChr = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] != curChr) {
                if (curCnt % k != 0) {
                    cnts.Push(curCnt % k);
                    chrs.Push(curChr);
                }

                if (chrs.Count > 0 && s[i] == chrs.Peek()) {
                    curCnt = cnts.Pop() + 1;
                    curChr = s[i];
                    chrs.Pop();
                } else {
                    curCnt = 1;
                    curChr = s[i];
                }
            } else {
                curCnt++;
            }
        }

        if (curCnt % k != 0) {
            cnts.Push(curCnt % k);
            chrs.Push(curChr);
        }

        var sb = new StringBuilder();
        while (chrs.Count > 0) {
            sb.Append(new string(chrs.Pop(), cnts.Pop()));
        }

        return sb.ToString();
    }
}

public class Solution {
    public string RemoveDuplicates(string s, int k) {
        var n = s.Length;
        var cntsChrs = new Stack<(int, char)>();
        var curCnt = 1;
        var curChr = s[n - 1];
        for (var i = n - 2; i >= 0; --i) {
            if (s[i] != curChr) {
                if (curCnt % k != 0) {
                    cntsChrs.Push((curCnt % k, curChr));
                }

                if (cntsChrs.Count > 0 && s[i] == cntsChrs.Peek().Item2) {
                    curCnt = cntsChrs.Pop().Item1 + 1;
                } else {
                    curCnt = 1;
                }

                curChr = s[i];
            } else {
                curCnt++;
            }
        }

        if (curCnt % k != 0) {
            cntsChrs.Push((curCnt % k, curChr));
        }

        var sb = new StringBuilder();
        while (cntsChrs.Count > 0) {
            var (cnts, chrs) = cntsChrs.Pop();
            sb.Append(new string(chrs, cnts));
        }

        return sb.ToString();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.RemoveDuplicates("deeedbbcccbdaa", 3));
        Console.WriteLine(s.RemoveDuplicates("pbbcggttciiippooaais", 2));
        Console.WriteLine(s.RemoveDuplicates("abcd", 2));
    }
}

//
// Created By jing At 11/4/25 22:11:24
//