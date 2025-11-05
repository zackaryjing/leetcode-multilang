# problem: https://leetcode.cn/problems/masking-personal-information/?envType=problem-list-v2&envId=3rBpGyas
from typing import *


class Solution:
    def maskPII(self, s: str) -> str:
        s = s.lower()
        if "@" in s:
            first, second = s.split("@")
            res = first[0] + "*" * 5 + first[-1] + "@" + second
        else:
            after = ""
            for ch in s:
                if ch not in ['+', '-', '(', ')', ' ']:
                    after += ch
            print("after", after)
            res = "***-***-" + after[-4:]
            if len(after) > 10:
                res = "+" + "*" * (len(after) - 10) + "-" + res
        return res


def main():
    test = Solution()
    print(test.maskPII("LeetCode@LeetCode.com"))
    print(test.maskPII("AB@qq.com"))
    print(test.maskPII("1(234)567-890"))


if __name__ == "__main__":
    main()

#
# Created by: zhiya At: 2025/11/5 22:58 
#
