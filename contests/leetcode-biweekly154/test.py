def next_power_of_2(n):
    if n <= 1:
        return 1
    # 如果n本身是2的幂，直接返回n
    if (n & (n - 1)) == 0:
        return n
    # 通过位运算调整n为下一个2的幂
    n -= 1  # 先减1
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16  # 对于n < 10^5，最多16位足够
    return n + 1  # 加1，得到下一个2的幂

print(next_power_of_2(10))
print(next_power_of_2(8))
print(next_power_of_2())
