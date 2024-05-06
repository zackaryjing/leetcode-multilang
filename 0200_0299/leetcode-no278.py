# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
    if version > 444:
        return True
    else:
        return False
class Solution:
    def firstBadVersion(self, n: int) -> int:
        right = n
        left = 0
        mid = (right+left)//2
        while right != mid and left != mid:
            print("T")
            if isBadVersion(mid):
                right = mid
                mid = (right+left)//2
            else:
                left = mid
                mid = (right+left)//2
        return mid+1
t = Solution()
print(t.firstBadVersion(1000))
