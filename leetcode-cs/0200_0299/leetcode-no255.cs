// problem: https://leetcode.cn/problems/verify-preorder-sequence-in-binary-search-tree/ 

using System.Collections.Generic;

namespace leetcodeNo255;

using System;

public class Solution2 {
    public bool VerifyPreorder(int[] preorder) {
        var st = new Stack<int>();
        st.Push(int.MaxValue);
        var last = int.MinValue;
        foreach (var num in preorder) {
            while (st.Peek() < num) {
                last = st.Peek();
                st.Pop();
            }

            st.Push(num);
            if (num < last) {
                return false;
            }
        }

        return true;
    }
}

public class Solution {
    public bool VerifyPreorder(int[] preorder) {
        var st = new Stack<int>([int.MaxValue]);
        var last = int.MinValue;
        foreach (var num in preorder) {
            while (st.Peek() < num) last = st.Pop();
            st.Push(num);
            if (num < last) return false;
        }

        return true;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.VerifyPreorder([5, 2, 1, 3, 6]));
        Console.WriteLine(s.VerifyPreorder([5, 2, 6, 1, 3]));
    }
}

//
// Created By ASUS At 12/2/2025 01:12:38
//