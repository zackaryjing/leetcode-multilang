// problem: https://leetcode.cn/problems/find-words-containing-character/?envType=daily-question&envId=2025-05-24

using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode_no2942;

public class Solution {
    public IList<int> FindWordsContaining(string[] words, char x) {
        var res = new List<int>();
        for (int i = 0; i < words.Length; i++) {
            if (words[i].Contains(x)) {
                res.Add(i);
            }
        }
        return res;
    }
    public IList<int> FindWordsContaining_3(string[] words, char x) {
        var res = new List<int>();
        var index = 0;
        foreach (var word in words) {
            if (word.Contains(x)) {
                res.Add(index);
            }
            index++;
        }
        return res;
    }

    public IList<int> FindWordsContaining_2(string[] words, char x) {
        var res = new List<int>();
        foreach (var word in words.Select((value, index) => new { value, index })) {
            if (word.value.Contains(x)) {
                res.Add(word.index);
            }
        }
        return res;
    }

    public static void Run() {
        var s = new Solution();
        Console.Write(string.Join(",", s.FindWordsContaining(["leet", "code"], 'e')));
    }
}

//
// Created By Zackary At 2025-05-24 01:01:32
//