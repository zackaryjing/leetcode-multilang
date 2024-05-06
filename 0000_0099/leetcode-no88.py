class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        length = m
        try:
            for k in nums2:
                for j in range(0,m+n):
                    if k < nums1[j]:
                        nums1.insert(j,k)
                        length += 1
                        nums1.pop()
                        break
                    elif j == length:
                        nums1.insert(j,k)
                        length += 1
                        nums1.pop()
                        break
            return nums1
        except:
            return nums1

class Solution2(object):
    def merge(self, nums1, m, nums2, n):
        del nums1[m:]
        nums1.extend(nums2)
        nums1.sort()
        return nums1

class Solution3(object):
    def merge(self, nums1, m, nums2, n):
        del nums1[m:]
        nums1.extend(nums2)
        return sorted(nums1)




t = Solution3()
print(t.merge([1,2,3,0,0,0],3,[2,5,6],3))
print([1,2,2,3,5,6])
print(t.merge([-1,0,0,3,3,3,0,0,0],6,[1,2,2],3))
print([-1,0,0,1,2,2,3,3,3])
print(t.merge([1,2,3,0,0,0],3,[2,5,6],3))
print([1,2,2,3,5,6])
