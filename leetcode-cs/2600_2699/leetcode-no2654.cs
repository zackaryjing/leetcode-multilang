// problem: 

using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo2654;

using System;

public class Solution {
    private BitArray isPrime;
    private int[] primes;
    private int mx;

    private void getPrimes() {
        isPrime = new BitArray(mx + 1, true);
        var tempPrimes = new List<int>((int)Math.Log(mx));
        for (var i = 2; i <= mx; ++i) {
            if (isPrime[i]) {
                var j = 2 * i;
                while (j < mx) {
                    isPrime[j] = false;
                    j += i;
                }

                tempPrimes.Add(i);
            }
        }

        primes = tempPrimes.ToArray();
    }

    private HashSet<int> getPrimeFactor(int num) {
        getPrimes();
        var res = new HashSet<int>();
        foreach (var prime in primes) {
            if (num % prime == 0) {
                res.Add(prime);
            }
        }

        return res;
    }

    public int MinOperations(int[] nums) {
        mx = nums.Max();
        var n = nums.Length;
        var factors = new HashSet<int>[n];

        var oneCnt = 0;
        for (var i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                oneCnt++;
            }

            factors[i] = getPrimeFactor(nums[i]);
        }

        if (oneCnt > 0) {
            return n - oneCnt;
        }

        var res = 0;
        bool found = false;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                factors[j].IntersectWith(factors[j + 1]);
                // Console.WriteLine($"i:{i} j:{j}");
                if (factors[j].Count == 0) {
                    res = n - i;
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        if (res == 0) {
            return -1;
        }

        return res + n - 1;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinOperations([2, 6, 3, 4]));
    }
}

//
// Created By ASUS At 11/13/2025 01:11:47
//