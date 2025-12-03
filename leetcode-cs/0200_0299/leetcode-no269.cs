// problem: https://leetcode.cn/problems/alien-dictionary/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace leetcodeNo269;

using System;

public class Solution {
    public string AlienOrder(string[] words) {
        var last = "";
        var n = words.Length;
        bool[,] prev = new bool[26, 26], next = new bool[26, 26];
        var indeg = new int[26];

        var shown = new bool[26];
        for (var i = 0; i < n; ++i) {
            var word = words[i];
            int m = int.Min(last.Length, word.Length), j = 0;
            for (; j < m; ++j) {
                int pc = word[j] - 'a', lc = last[j] - 'a';
                shown[pc] = true;
                if (pc == lc) continue;
                prev[pc, lc] = true;
                next[lc, pc] = true;
                break;
            }

            if (j == m && j < last.Length) return "";
            for (; j < word.Length; ++j) {
                var pc = word[j] - 'a';
                shown[pc] = true;
            }

            last = word;
        }


        var q = new Queue<int>();
        var total = 0;
        for (var i = 0; i < 26; ++i) {
            total += shown[i] ? 1 : 0;
            for (var j = 0; j < 26; ++j) {
                indeg[i] += prev[i, j] ? 1 : 0;
            }

            if (shown[i] && indeg[i] == 0) q.Enqueue(i);
        }

        var sb = new StringBuilder();
        while (q.Count > 0) {
            var cur = q.Dequeue();
            sb.Append((char)(cur + 'a'));
            for (var nx = 0; nx < 26; ++nx) {
                if (!next[cur, nx]) continue;
                indeg[nx]--;
                if (indeg[nx] == 0) {
                    q.Enqueue(nx);
                }
            }
        }

        var res = sb.ToString();
        return res.Length == total ? res : "";
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        // Console.WriteLine(s.AlienOrder(["wrt", "wrf", "er", "ett", "rftt"]));
        // Console.WriteLine(s.AlienOrder(["z", "x"]));
        // Console.WriteLine(s.AlienOrder(["z", "x", "z"]));
        // Console.WriteLine(s.AlienOrder(["z", "z"]));
        Console.WriteLine(s.AlienOrder(["ac", "ab", "zc", "zb"]));
        Console.WriteLine(s.AlienOrder(["abc", "ab"]));
    }
}

//
// Created By ASUS At 12/2/2025 18:12:07
//
// var preChar = word[0] - 'a';
// for (var j = 1; j < word.Length; ++j) {
//     if (preChar >= 0 && word[j] != preChar) {
//         var curChar = word[j] - 'a';
//         prev[curChar].Add(preChar);
//         next[preChar].Add(curChar);
//         preChar = curChar;
//     }
// }