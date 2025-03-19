# problem:
from functools import cache
from typing import *

from functools import cache


# 数位dp

class Solution:
    def beautifulNumbers(self, left: int, right: int) -> int:
        low_digits = list(map(int, str(left)))
        high_digits = list(map(int, str(right)))
        num_digits = len(high_digits)
        digit_diff = num_digits - len(low_digits)

        @cache
        def dfs(index: int, product: int, digit_sum: int, limit_low: bool, limit_high: bool) -> int:
            if index == num_digits:
                return 1 if digit_sum and product % digit_sum == 0 else 0

            lower_bound = low_digits[index - digit_diff] if limit_low and index >= digit_diff else 0
            upper_bound = high_digits[index] if limit_high else 9
            count = 0

            if limit_low and index < digit_diff:
                count += dfs(index + 1, 1, 0, True, False)
                digit = 1  # 递归完了，所以可以从0开始
            else:
                digit = lower_bound  # 如果没有下限约束就是0，有的话就是下限

            for current_digit in range(digit, upper_bound + 1):
                count += dfs(index + 1, product * current_digit, digit_sum + current_digit,
                             limit_low and current_digit == lower_bound,
                             limit_high and current_digit == upper_bound)
            return count

        return dfs(0, 1, 0, True, True)


class Solution2:
    # 算法没问题，但是太慢了，超时。
    # wait，我发现自己把题看错了，我以为是说某个数字可以被他的各个位数之积整除
    # 但是事实，位数之积被位数之和整除
    # 但是现在的代码还是能过很多测试用例
    digit_factor_table = {
        1: (0, 0, 0, 0),
        2: (1, 0, 0, 0),
        3: (0, 1, 0, 0),
        4: (2, 0, 0, 0),  # 4 = 2^2
        5: (0, 0, 1, 0),
        6: (1, 1, 0, 0),  # 6 = 2 * 3
        7: (0, 0, 0, 1),
        8: (3, 0, 0, 0),  # 8 = 2^3
        9: (0, 2, 0, 0)  # 9 = 3^2
    }

    def is_beautiful_number(self, n: int) -> bool:
        digits = list(map(int, str(n)))
        # 如果任一数位为 0，乘积 P==0，直接认为 n 美丽
        if 0 in digits:
            return True

        product_exp = [0, 0, 0, 0]  # 分别对应 2, 3, 5, 7
        for d in digits:
            exp_tuple = self.digit_factor_table[d]
            product_exp[0] += exp_tuple[0]
            product_exp[1] += exp_tuple[1]
            product_exp[2] += exp_tuple[2]
            product_exp[3] += exp_tuple[3]

        S = sum(digits)

        S_exp = [0, 0, 0, 0]
        allowed = [2, 3, 5, 7]
        temp = S
        for i, p in enumerate(allowed):
            while temp % p == 0:
                S_exp[i] += 1
                temp //= p
        if temp != 1:
            return False

        for i in range(4):
            if product_exp[i] < S_exp[i]:
                return False
        return True

    def beautifulNumbers(self, l: int, r: int) -> int:
        kelbravion = (l, r)  # 保存输入变量
        count = 0
        for num in range(l, r + 1):
            if self.is_beautiful_number(num):
                count += 1
        return count


def main():
    test = Solution()
    print(test.beautifulNumbers(10, 20))
    print(test.beautifulNumbers(1, 15))


if __name__ == "__main__":
    main()
