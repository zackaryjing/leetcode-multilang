from typing import *

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        m = len(baskets)
        used = [False for _ in range(m)]
        not_found = [True for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if not used[j] and baskets[j] >= fruits[i]:
                    used[j] = True
                    not_found[i] = False
                    break
            print("nf:", not_found)
            print("u:", used)
        # print(used)
        # print(not_found)
        return sum(not_found)

def main():
    test = Solution()
    print(test.numOfUnplacedFruits([38, 65, 8], [27,10,47]))
    print(test.numOfUnplacedFruits([98,51,70,9,21], [21,52,3,30,16]))
    print(test.numOfUnplacedFruits([3, 6, 1, 2, 3, 8], [6, 4, 7, 3, 5, 12]))
    print(test.numOfUnplacedFruits([3,6,1],[6,4,7]))
    print(test.numOfUnplacedFruits([4,2,5],[3,5,4]))

class Solution2:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        # fruits.sort()
        # baskets.sort()
        fi,bi = 0,0
        n = len(fruits)
        m = len(baskets)
        while fi < n and bi < m:
            print(fi,bi)
            if baskets[bi] >= fruits[fi]:
                bi += 1
                fi += 1
            else:
                bi += 1
        return n - fi






if __name__ == "__main__":
    main()

