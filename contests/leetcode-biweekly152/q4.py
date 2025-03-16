# problem:
from typing import *


class Solution:
    # 预先构造 1~9 的质因数指数表，顺序对应 (2, 3, 5, 7)
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
    print(test.beautifulNumbers(10,20))
    print(test.beautifulNumbers(1,15))


if __name__ == "__main__":
    main()
