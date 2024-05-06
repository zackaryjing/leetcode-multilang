class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        a = '%0.32d' %int(bin(n).replace('0b',''))
        a = a[::-1]
        print(int(a,2))

t = Solution()
print(t.reverseBits(7))