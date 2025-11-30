// problem: https://leetcode.cn/problems/shortest-word-distance-ii/?envType=problem-list-v2&envId=fMpGFr6b

using System.Collections.Generic;
using System.Threading;

namespace leetcodeNo244;

using System;

public class WordDistance {
    private readonly Dictionary<string, List<int>> position = new();

    public WordDistance(string[] wordsDict) {
        var n = wordsDict.Length;
        for (var i = 0; i < n; ++i) {
            var word = wordsDict[i];
            if (position.TryGetValue(word, out var value)) {
                value.Add(i);
            } else {
                position[word] = [i];
            }
        }
    }


    public int Shortest(string word1, string word2) {
        var i = 0;
        var j = 0;
        var list1 = position[word1];
        var list2 = position[word2];
        var n = list1.Count;
        var m = list2.Count;
        var res = int.MaxValue;
        while (i < n && j < m) {
            var a = list1[i];
            var b = list2[j];
            res = int.Min(res, int.Abs(a - b));
            if (a < b) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.Shortest(word1,word2);
 */
public class Test {
    public static void Run() {
        var s = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
        Console.WriteLine(s.Shortest("coding", "practice"));
        Console.WriteLine(s.Shortest("coding", "makes"));
    }
}

//
// Created By jing At 11/30/25 16:11:01
//