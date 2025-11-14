// problem: 

using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo2654;

using System;

public class Solution2 {
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

            if (prime > num) break;
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

public class Solution {
    private int gcd(int a, int b) {
        while (b != 0) {
            var temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    public int MinOperations(int[] nums) {
        var n = nums.Length;

        var oneCnt = 0;
        for (var i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                oneCnt++;
            }
        }

        if (oneCnt > 0) {
            return n - oneCnt;
        }

        var res = 0;
        bool found = false;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                nums[j] = gcd(nums[j], nums[j + 1]);
                if (nums[j] == 1) {
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
        // Console.WriteLine(s.MinOperations([2, 6, 3, 4]));
        Console.WriteLine(s.MinOperations([
            574053, 773472, 859785, 669711, 92650, 379778, 329144, 378132, 96755, 13463, 580605, 851406, 378945, 249413,
            81912, 412250, 418652, 867997, 694312, 969118, 849092, 768265, 232008, 312713, 709638, 337122, 156872,
            116618, 501596, 646517, 875518, 607344, 84507, 957143, 57211, 843742, 388089, 63528, 481294, 98577, 863438,
            510042, 260973, 9755, 775883, 459210, 7888, 159291, 966507, 909610
        ]));
    }
}

//
// Created By ASUS At 11/13/2025 01:11:47
//