from typing import *


class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        n = len(flowers)
        flowers = sorted([min(x, target) for x in flowers], reverse=True)
        total = sum(flowers)
        ans = 0

        if target * n - total <= newFlowers:
            ans = full * n
        pre = ptr = 0
        for i in range(n):
            if i != 0:
                pre += flowers[i - 1]
            if flowers[i] == target:
                continue

            rest = newFlowers - (target * i - pre)
            if rest < 0:
                break

            while not (ptr >= i and flowers[ptr] * (n - ptr) - total <= rest):
                total -= flowers[ptr]
                ptr += 1
            rest -= flowers[ptr] * (n - ptr) - total
            ans = max(ans, full * i + partial * (min(flowers[ptr] + rest // (n - ptr), target - 1)))
        return ans


def main():
    test = Solution()
    test.maximumBeauty([1, 1, 3, 5, 6, 7], 19, 50, 50, 50);
    # print(test.maximumBeauty([1, 3, 1, 1], 7, 6, 12, 1))
    # print(test.maximumBeauty([2, 4, 5, 3], 10, 5, 2, 6))


if __name__ == "__main__":
    main()


class Solution2:
    # 作废。It doesn't work.
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        flowers.sort()
        low_part_prices = [0]
        low_part = [flowers[1]]
        low_temp = [1]
        n = len(flowers)
        cur = 0
        i = 1
        temp = 0
        while i < n:
            temp += 1
            while flowers[i] == flowers[i - 1]:
                temp += 1
                i += 1
            if flowers[i] > flowers[i - 1]:
                is_end = False
                for j in range(1, flowers[i] - flowers[i - 1] + 1):
                    cur += temp
                    print(f'J: {j}, cur: {cur}, temp: {temp}')
                    if cur > newFlowers:
                        is_end = True
                        break
                    low_part_prices.append(cur)
                    low_part.append(flowers[i - 1] + j)
                    low_temp.append(temp)
                if is_end: break
            i += 1
        print(low_part_prices)
        print(low_part)
        print(low_temp)

        ans = 0

        k = n - 1
        while target <= flowers[k]:
            k -= 1
        cost = 0
        for i in range(len(low_part) - 1, -1, -1):
            rest = newFlowers - low_part_prices[i]
            # cost += target - flowers[k]
            while cost + target - flowers[k] <= rest:
                # print("h")
                k -= 1
                cost += target - flowers[k]
            # print(f"cost: {cost}, k: {k} , rest :{rest}, i: {i}")
            ans = max(ans, (n - 1 - k) * full + low_part[i] * partial)
            # print(f"ans: {ans}, {n - 1 - k} {full}")
        return ans
