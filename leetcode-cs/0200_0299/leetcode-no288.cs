// problem: https://leetcode.cn/problems/unique-word-abbreviation/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections.Generic;
using System.Linq;
using System.Net;

namespace leetcodeNo288;

using System;

public class ValidWordAbbr {
    private readonly Dictionary<string, List<string>> dict = new();

    public ValidWordAbbr(string[] dictionary) {
        var dd = new HashSet<string>(dictionary);
        foreach (var word in dd) {
            var key = word.Length > 2 ? $"{word[0]}{word.Length - 2}{word[^1..]}" : word;
            Console.WriteLine($"key: {key}");
            if (dict.TryGetValue(key, out var value)) {
                value.Add(word);
            } else {
                dict[key] = [word];
            }
        }
    }

    public bool IsUnique(string word) {
        var key = word.Length > 2 ? $"{word[0]}{word.Length - 2}{word[^1..]}" : word;
        return !dict.ContainsKey(key) || dict[key].Count == 1 && dict[key][0] == word;
    }
}

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.IsUnique(word);
 */
public class Test {
    public static void Run() {
        var s = new ValidWordAbbr(["deer", "door", "cake", "card"]);
        Console.WriteLine(s.IsUnique("deer"));
        Console.WriteLine(s.IsUnique("cart"));
        Console.WriteLine(s.IsUnique("cane"));
        Console.WriteLine(s.IsUnique("make"));
        Console.WriteLine(s.IsUnique("cake"));
    }
}

//
// Created By ASUS At 12/5/2025 15:12:28
//