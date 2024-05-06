class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> list[int]:
        res = [0 for i in range(num_people)]
        pos = 0
        current = 1
        while candies:
            if pos < num_people:
                if candies >= current:
                    candies -= current
                    res[pos] += current
                    current += 1
                    pos += 1
                else:
                    res[pos] += candies
                    break
            else:
                pos = 0
        return res

t = Solution()
print(t.distributeCandies(7,4))
print(t.distributeCandies(10,3))

