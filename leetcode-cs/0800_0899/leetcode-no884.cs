// problem: https://leetcode.cn/problems/uncommon-words-from-two-sentences/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo884;

using System;
using System.Collections.Generic;

public class Solution {
    public string[] UncommonFromSentences(string s1, string s2) {
        var cnt = new Dictionary<string, int>();
        foreach (var word in s1.Split(' ')) {
            if (!cnt.TryAdd(word, 1)) {
                cnt[word] += 1;
            }
        }

        foreach (var word in s2.Split(' ')) {
            if (!cnt.TryAdd(word, 1)) {
                cnt[word] += 1;
            }
        }

        List<string> res = new List<string>();
        foreach (var kv in cnt) {
            if (kv.Value == 1) {
                res.Add(kv.Key);
            }
        }

        return res.ToArray();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(",", s.UncommonFromSentences("this apple is sweet", "this apple is sour")));
        Console.WriteLine(string.Join(",", s.UncommonFromSentences("this apple is sweet", "this apple is sour")));
    }
}

//
// Created By jing At 10/31/25 21:10:32
//