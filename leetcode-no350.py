class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result = []
        inner,outter = [nums1,nums2] if len(nums2)>len(nums1) else [nums2,nums1]
        for i in inner:
            if i in outter:
                result.append(i)
                outter.remove(i)
        return result

t = Solution()
print(t.intersect([1,2,2,1],[2,2]))
print(t.intersect([1,2],[1,1]))