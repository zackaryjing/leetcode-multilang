class Solution:
    def arrayNesting(self, nums: list[int]) -> int:
        visited = [0]
        n = len(nums)
        def find(node,path):
            if not (temp := nums[node]) in path and temp not in visited:
                getback = find(temp,path+[temp])
                print("getback", getback,'node',nums[node])
                nums[node] = getback
                return getback
            else:
                nums[node] = nums[temp]
                visited.extend(path)
                return nums[temp]
        for i in range(n):
            if not i in visited:
                find(i,[])
        find(nums[0],[])
        return nums

t = Solution()
print(t.arrayNesting([5,4,0,3,1,6,2]))

