// problem: https://leetcode.cn/problems/rotated-digits/?envType=problem-list-v2&envId=3rBpGyas 

namespace leetcodeNo788;

using System;

public class Solution2 {
    public int RotatedDigits(int n) {
        var res = 0;
        for (var i = 1; i <= n; ++i) {
            var valid = false;
            var t = i;
            while (t > 0) {
                var k = t % 10;
                switch (k) {
                    case 3:
                    case 4:
                    case 7:
                        goto Next;
                    case 2:
                    case 9:
                    case 5:
                    case 6:
                        valid = true;
                        break;
                }

                t /= 10;
            }

            if (valid) res++;
            Next: ;
        }

        return res;
    }
}

public class Solution {
    public int RotatedDigits(int n) {
        var res = 0;
        for (var i = 1; i <= n; ++i) {
            var valid = false;
            var t = i;
            while (t > 0) {
                var k = t % 10;
                if (k is 3 or 4 or 7) {
                    valid = false;
                    break;
                }

                if (k is 2 or 9 or 5 or 6) valid = true;
                t /= 10;
            }

            if (valid) res++;
        }

        return res;
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.RotatedDigits(10));
        Console.WriteLine(s.RotatedDigits(857));
    }
}

//
// Created By jing At 12/21/25 15:04:30
//