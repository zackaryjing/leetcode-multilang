// problem: https://leetcode.cn/problems/count-operations-to-obtain-zero/?envType=daily-question&envId=2025-11-09 

namespace leetcodeNo2169;

using System;

public class Solution {
    public int CountOperations(int num1, int num2) {
        var res = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 < num2) {
                (num1, num2) = (num2, num1);
            }

            res += num1 / num2;
            num1 %= num2;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.CountOperations(2, 3));
        Console.WriteLine(s.CountOperations(10, 10));
    }
}

//
// Created By ASUS At 11/9/2025 14:11:53
//