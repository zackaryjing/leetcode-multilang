// problem: https://leetcode.cn/problems/factor-combinations/?envType=problem-list-v2&envId=fMpGFr6b 

using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo254;

using System;

class StructuralIntArrayComparer : IEqualityComparer<int[]> {
    public bool Equals(int[] x, int[] y) {
        return StructuralComparisons.StructuralEqualityComparer.Equals(x, y);
    }

    public int GetHashCode(int[] obj) {
        return StructuralComparisons.StructuralEqualityComparer.GetHashCode(obj);
    }
}

public class Solution {
    // Terrible performance.
    bool isPrime(int n) {
        var limit = (int)Math.Sqrt(n) + 1;
        for (var i = 2; i < limit; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int[] dispose(int n) {
        if (isPrime(n)) return [];

        List<int> res = [];
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                while (n % i == 0) {
                    n /= i;
                    res.Add(i);
                }
            }
        }

        return res.ToArray();
    }

    public IList<IList<int>> GetFactors(int n) {
        var comparer = new StructuralIntArrayComparer();
        if (isPrime(n)) {
            return [];
        }

        var sampleSet =
            new HashSet<int[]>(comparer);
        sampleSet.Add([]);

        var factor = dispose(n);
        // Console.WriteLine($"factor: {string.Join(" ", factor)}");
        foreach (var num in factor) {
            var newSet =
                new HashSet<int[]>(comparer);
            foreach (var sample in sampleSet) {
                for (var i = 0; i < sample.Length; ++i) {
                    var tmp = new int[sample.Length];
                    sample.CopyTo(tmp, 0);
                    tmp[i] *= num;
                    Array.Sort(tmp);
                    newSet.Add(tmp);
                }

                var newSample = new int[sample.Length + 1];
                sample.CopyTo(newSample, 0);
                newSample[sample.Length] = num;
                Array.Sort(newSample);
                newSet.Add(newSample);
            }

            sampleSet = newSet;
        }

        sampleSet.Remove([n]);
        return sampleSet.Cast<IList<int>>().ToList();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join("\n", s.GetFactors(12).Select((list) => string.Join(",", list))));
        Console.WriteLine(string.Join("\n", s.GetFactors(30).Select((list) => string.Join(",", list))));
        Console.WriteLine(string.Join("\n", s.GetFactors(32).Select((list) => string.Join(",", list))));
        Console.WriteLine(string.Join("\n", s.GetFactors(4).Select((list) => string.Join(",", list))));
    }
}

//
// Created By ASUS At 12/1/2025 17:12:34
//