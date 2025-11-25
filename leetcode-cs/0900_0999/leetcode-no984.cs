// problem: https://leetcode.cn/problems/string-without-aaa-or-bbb/?envType=problem-list-v2&envId=3rBpGyas 

using System.Text;

namespace leetcodeNo984;

using System;

public class Solution2 {
    // kind version
    public string StrWithout3a3b(int a, int b) {
        string res = "";
        char[] cand = ['a', 'b'];
        int[] cnt = [a, b];
        int last = a > b ? 1 : 0;
        while (cnt[0] > 0 || cnt[1] > 0) {
            var cur = last ^ 1;
            if (cnt[last] >= cnt[cur]) {
                res += cand[cur];
                cnt[cur]--;
            } else {
                res += cand[cur];
                if (cnt[cur] > 1) {
                    res += cand[cur];
                }

                cnt[cur] -= 2;
            }

            last = cur;
        }

        return res;
    }
}

public class Solution {
    // evil version
    public string StrWithout3a3b(int a, int b) {
        var sb = new StringBuilder(a + b);
        int[] cnt = [a, b];
        var cur = a > b ? 0 : 1;
        do {
            sb.Append((char)('a' + cur));
            if (cnt[cur ^ 1] < cnt[cur] && cnt[cur]-- > 1)
                sb.Append((char)('a' + cur));
        } while (--cnt[(cur ^= 1) ^ 1] > 0 || cnt[cur] > 0);

        return sb.ToString();
    }
}

public class Test {
    public static void Run() {
        var s = new Solution();
        Console.WriteLine(s.StrWithout3a3b(1, 2));
        Console.WriteLine(s.StrWithout3a3b(4, 1));
    }
}

//
// Created By jing At 11/17/25 20:11:14
//
