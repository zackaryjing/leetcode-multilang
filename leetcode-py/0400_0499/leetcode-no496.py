class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result = []
        length = len(nums2)
        for i in nums1:
            k = 1
            for j in range(nums2.index(i),length):
                if nums2[j] > i:
                    result.append(nums2[j])
                    k = 0
                    break
            if k:
                result.append(-1)
        return result

t = Solution()
print(t.nextGreaterElement([4,1,2],[1,3,4,2]))
print(t.nextGreaterElement([2,4],[1,2,3,4]))
