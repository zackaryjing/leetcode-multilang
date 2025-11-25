// problem: https://leetcode.cn/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/ 

using System.Collections.Generic;

namespace leetcodeNo1526;

using System;

public class Solution2 {
    public int MinNumberOperations(int[] target) {
        var st = new Stack<int>();
        st.Push(0);
        int res = 0;
        foreach (int num in target) {
            if (num >= st.Peek()) {
                res += num - st.Peek();
                st.Push(num);
            } else {
                while (st.Count > 0 && num < st.Peek()) {
                    st.Pop();
                }

                st.Push(num);
            }
        }

        return res;
    }
}

public class Solution {
    public int MinNumberOperations(int[] target) {
        int last = 0;
        int res = 0;
        foreach (int num in target) {
            if (num > last) {
                res += num - last;
            }

            last = num;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.MinNumberOperations([1, 2, 3, 2, 1]));
        Console.WriteLine(s.MinNumberOperations([3, 1, 1, 2]));
        Console.WriteLine(s.MinNumberOperations([3, 1, 5, 4, 2]));
    }
}

//
// Created By ASUS At 11/9/2025 15:11:53
//