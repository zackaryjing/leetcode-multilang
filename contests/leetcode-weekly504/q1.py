# problem:  
from typing import *


class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        return sum([int(k) * v for k, v in Counter(str(n)).items()])


def main():
    test = Solution()
    print(test.digitFrequencyScore(10))
    print(test.digitFrequencyScore(122))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 5/31/2026 10:29 AM 
#
