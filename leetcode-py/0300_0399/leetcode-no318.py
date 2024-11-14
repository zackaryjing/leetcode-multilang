from typing import *
from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        data = defaultdict(int)
        for word in words:
            length = len(word)
            val = 0
            for ch in word:
                val |= 2 ** (ord(ch) - ord('a'))
            if data[val] < length:
                data[val] = length
        maxum = 0
        data = list(data.items())
        for j in range(h := len(data)):
            for k in range(j+1,h):
                # print(k,j,maxum)
                if not (data[j][0] & data[k][0]):
                    tmp = data[j][1] * data[k][1]
                    if tmp > maxum:
                        maxum = tmp
                
        # print(data)
        return maxum
print(bin(4))
print(bin(6))
print(bin(6 & 4))
t = Solution()
print(t.maxProduct(["abcw","baz","foo","bar","xtfn","abcdef"]))
print(t.maxProduct(["a","aa","aaa","aaaa"]))

