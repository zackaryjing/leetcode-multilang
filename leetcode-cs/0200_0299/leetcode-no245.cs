// problem: https://leetcode.cn/problems/shortest-word-distance-iii/?envType=problem-list-v2&envId=fMpGFr6b 

namespace leetcodeNo245;

using System;

public class Solution {
    public int ShortestWordDistance(string[] wordsDict, string word1, string word2) {
        var n = wordsDict.Length;
        int aPos = -n, bPos = -n;
        var res = n - 1;
        var k = word1 == word2;
        for (var i = 0; i < n; ++i) {
            var w = wordsDict[i];
            if (w == word1) {
                aPos = i;
                res = int.Min(res, int.Abs(aPos - bPos));
            }

            if (w == word2) {
                bPos = i;
                if (!k) res = int.Min(res, int.Abs(aPos - bPos));
            }
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
    }
}

//
// Created By jing At 11/30/25 17:11:09
//