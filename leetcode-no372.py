class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        MOD = 1337
        ans = 1
        for i in reversed(b):
            ans = ans * pow(a,i,MOD) % MOD
            a = pow(a,10,MOD)
        return ans