class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        total = 0
        leftmax = rightmax = 0
        left,right = 0,len(height)-1
        while left<right:
            leftmax = max(leftmax,height[left])
            rightmax = max(rightmax,height[right])
            if leftmax<rightmax:
                total+= leftmax-height[left]
                left += 1
            else:
                total += rightmax - height[right]
                right -= 1
        return total

t = Solution()
print(t.trap([1,0,2,3,1,4,2,3,1,2]))
