// problem: https://leetcode.cn/problems/shortest-word-distance/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo243;

using System;

public class Solution {
    public int ShortestDistance(string[] wordsDict, string word1, string word2) {
        var n = wordsDict.Length;
        var aPos = -n;
        var bPos = n - 1;
        var res = n - 1;
        for (var i = 0; i < n; ++i) {
            var w = wordsDict[i];
            if (w == word1) {
                aPos = i;
                res = int.Min(res, int.Abs(aPos - bPos));
            }

            if (w == word2) {
                bPos = i;
                res = int.Min(res, int.Abs(aPos - bPos));
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.ShortestDistance(["practice", "makes", "perfect", "coding", "makes"], "coding",
            "practice"));
    }
}

//
// Created By jing At 11/30/25 16:11:04
//