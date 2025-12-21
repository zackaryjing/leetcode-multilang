// problem: https://leetcode.cn/problems/word-pattern-ii/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Text;

namespace leetcodeNo291;

using System;

public class Solution {
    private string p;
    private string t;
    Dictionary<char, string> matches = new();
    private bool hasAns = false;
    private HashSet<string> ts = new();

    private void BackTrace(int ppos, int spos) {
        if (ppos == p.Length) {
            if (spos == t.Length) hasAns = true;
            return;
        }

        var c = p[ppos];
        if (matches.TryGetValue(c, out var part)) {
            if (part.Length + spos > t.Length || t[spos..(spos + part.Length)] != part) return;
            BackTrace(ppos + 1, spos + part.Length);
        } else {
            var nValSb = new StringBuilder();
            for (var j = 1; j <= t.Length - spos; ++j) {
                nValSb.Append(t[spos + j - 1]);
                var nVal = nValSb.ToString();
                if (ts.Contains(nVal)) continue;
                matches[c] = nVal;
                ts.Add(nVal);
                BackTrace(ppos + 1, spos + j);
                ts.Remove(nVal);
                matches.Remove(c);
            }
        }
    }

    public bool WordPatternMatch(string pattern, string s) {
        p = pattern;
        t = s;
        BackTrace(0, 0);
        return hasAns;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(s.WordPatternMatch("abab", "redblueredblue"));
        // Console.WriteLine(s.WordPatternMatch("aaaa", "asdasdasdasd"));
        Console.WriteLine(s.WordPatternMatch("aabb", "xyzabcxzyabc"));
        // Console.WriteLine(s.WordPatternMatch("ab", "aa"));
    }
}

//
// Created By ASUS At 12/5/2025 15:12:24
//