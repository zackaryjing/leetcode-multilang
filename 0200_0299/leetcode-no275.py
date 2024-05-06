class Solution:
    def hIndex(self, citations: list[int]) -> int:
        # 尝试用二分实现
        citations.reverse()
        left = 0
        right = len(citations)-1
        if citations.count(0) == right + 1:
            return [0]
        while left < right:
            mid = (left + right + 1) // 2
            if citations[mid] > mid:
                left = mid
            else:
                right = mid - 1
        return left + 1

t = Solution()
print(t.hIndex([0,1,3,5,6]))
print(t.hIndex([1,2,100]))
