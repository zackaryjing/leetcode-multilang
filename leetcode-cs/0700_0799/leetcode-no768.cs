// problem: https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/?envType=problem-list-v2&envId=3rBpGyas 

using System.Collections.Generic;
using System.Linq;

namespace leetcodeNo768;

using System;

public class Solution2 {
    // pass too slow due to the sort process
    public int MaxChunksToSorted(int[] arr) {
        var n = arr.Length;
        var posArray = new int[n];
        var temp = arr.Select((num, index) => (num, index)).OrderBy(val => val.num).ToArray();
        for (var i = 0; i < temp.Length; ++i) {
            posArray[temp[i].index] = i;
        }

        var endPos = 0;
        var curPos = 0;
        var res = 0;
        while (endPos < n) {
            while (curPos <= endPos) {
                endPos = int.Max(endPos, posArray[curPos]);
                curPos++;
            }

            endPos = curPos;
            res++;
        }

        return res;
    }
}

public class Solution3 {
    public int MaxChunksToSorted(int[] arr) {
        // stack (max,min)
        // ok, but not best
        Stack<(int, int)> st = new Stack<(int, int)>([(-1, -1)]);
        foreach (var num in arr) {
            var (cmx, cmn) = st.Peek();
            if (num >= cmx) {
                st.Push((num, num));
            } else if (num < cmn) {
                var nmx = cmx;
                var nmn = num;
                st.Pop();
                while (num < st.Peek().Item1) {
                    var mn = st.Peek().Item2;
                    nmn = int.Min(nmn, mn);
                    st.Pop();
                }

                st.Push((nmx, nmn));
            }

            // Console.WriteLine(string.Join(",", st.Select(x => $"({x.Item1} {x.Item2})")));
        }

        return st.Count - 1;
    }
}

public class Solution {
    public int MaxChunksToSorted(int[] arr) {
        Stack<int> st = new Stack<int>();
        foreach (var num in arr) {
            if (st.Count == 0 || num >= st.Peek()) {
                st.Push(num);
            } else {
                var cmx = st.Pop();
                while (st.Count > 0 && num < st.Peek()) {
                    st.Pop();
                }

                st.Push(cmx);
            }
        }

        return st.Count;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MaxChunksToSorted([5, 4, 3, 2, 1]));
        Console.WriteLine(s.MaxChunksToSorted([2, 1, 3, 4, 4]));
    }
}

//
// Created By jing At 11/10/25 15:11:42
//