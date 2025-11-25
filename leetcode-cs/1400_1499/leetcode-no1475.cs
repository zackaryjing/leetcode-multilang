// problem: https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;

namespace leetcodeNo1475;

using System;

public class Solution2 {
    public int[] FinalPrices(int[] prices) {
        var st = new Stack<int>();
        var n = prices.Length;
        var res = new int[n];
        for (var i = n - 1; i >= 0; --i) {
            Console.WriteLine($"st: {string.Join(" ", st)}");
            if (st.Count == 0) {
                res[i] = prices[i];
            } else if (st.Peek() <= prices[i]) {
                res[i] = prices[i] - st.Peek();
            } else {
                while (st.Count > 0 && st.Peek() > prices[i]) {
                    st.Pop();
                }

                if (st.Count > 0) {
                    res[i] = prices[i] - st.Peek();
                } else {
                    res[i] = prices[i];
                }
            }

            st.Push(prices[i]);
        }

        return res;
    }
}

public class Solution3 {
    public int[] FinalPrices(int[] prices) {
        var st = new Stack<int>();
        st.Push(0);
        var n = prices.Length;
        var res = new int[n];
        for (var i = n - 1; i >= 0; --i) {
            while (st.Peek() > prices[i]) {
                st.Pop();
            }

            res[i] = prices[i] - st.Peek();
            st.Push(prices[i]);
        }

        return res;
    }
}

public class Solution {
    public int[] FinalPrices(int[] prices) {
        var st = new Stack<int>();
        st.Push(0);
        var n = prices.Length;
        for (var i = n - 1; i >= 0; --i) {
            while (st.Peek() > prices[i]) {
                st.Pop();
            }

            var t = prices[i];
            prices[i] -= st.Peek();
            st.Push(t);
        }

        return prices;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(string.Join(" ", s.FinalPrices([8, 4, 6, 2, 3])));
    }
}

//
// Created By ASUS At 11/25/2025 15:11:20
//