class Solution2(object):
    def maxArea(self, height):  #双指针法
        """
        :type height: List[int]
        :rtype: int
        """
        right = len(height)-1
        left = 0
        maxarea = 0
        while True:
            each = min(height[left],height[right])*(right-left)
            if each > maxarea:
                maxarea = each
            if height[left] > height[right]:
                right -= 1
            elif height[left] < height[right]:
                left += 1
            else:
                if height[left+1] <= height[right-1]:
                    right -= 1
                else:
                    left += 1
            if left >= right:
                break
        return maxarea


class Solution(object):
    def maxArea(self, height):  #改进了一点点变量储存
        """
        :type height: List[int]
        :rtype: int
        """
        right = len(height)-1
        left = 0
        maxarea = 0
        while True:
            leftone = height[left]
            rightone = height[right]
            each = min(leftone,rightone)*(right-left)
            if each > maxarea:
                maxarea = each
            if leftone > rightone:
                right -= 1
            elif leftone < rightone:
                left += 1
            else:
                if height[left+1] <= height[right-1]:
                    right -= 1
                else:
                    left += 1
            if left >= right:
                break
        return maxarea
t = Solution()
print(t.maxArea([1,8,6,2,5,4,8,3,7]))