import math
class Solution(object):
    def countBalls(self, lowLimit, highLimit):
        """
        :type lowLimit: int
        :type highLimit: int
        :rtype: int
        """
        boxes = [0]*int(math.log(highLimit,10)+1)*9
        for i in range(lowLimit,highLimit+1):
            sum = 0
            times = 1
            while i >0:
                sum += i%10**times
                i //= 10
            boxes[sum] += 1
        return max(boxes)

t = Solution()
print(t.countBalls(1,10))