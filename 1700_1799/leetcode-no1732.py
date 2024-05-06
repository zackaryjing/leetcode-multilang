class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        top = gain[0]
        sum = 0
        for i in gain:
            sum += i
            if sum > top:
                top = sum
        return top if top > 0 else 0


t = Solution()
print(t.largestAltitude([-4,-3,-2,-1,4,3,2]))
print(t.largestAltitude([-5,1,5,0,-7]))