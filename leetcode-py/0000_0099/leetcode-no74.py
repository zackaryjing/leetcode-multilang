class Solution2:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        leftbegin = [i[0] for i in matrix]
        left = 0
        right = len(leftbegin) - 1
        if leftbegin[right] == target:
            return True
        while left < right:
            mid = (left + right + 1) // 2
            print(left,mid,right)
            if leftbegin[mid] < target:
                left = mid
            elif leftbegin[mid] > target:
                right = mid - 1
            else:
                return True
        print(mid)

        midcopy = mid
        left = 0
        right = len(matrix[0])
        while left < right:
            mid = (left + right + 1) // 2
            print(left, mid, right, "***")
            if matrix[midcopy][mid] < target:
                left = mid
            # elif matrix[midcopy][mid] == target:
            #     return True
            else:
                right = mid - 1
        print(midcopy,mid)
        if matrix[midcopy][mid] == target:
            return False
        return True

class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        line = len(matrix)
        if target < matrix[0][0]:
            return False
        for i in range(len(matrix)):
            if matrix[i][0] > target:
                line = i
                break
            elif matrix[i][0] == target:
                return True
        left = 0
        right = len(matrix[0]) - 1
        mid = 0
        while left < right:
            mid = (left + right + 1) // 2
            if matrix[line-1][mid] < target:
                left = mid
            elif matrix[line-1][mid] == target:
                return True
            else:
                right = mid - 1
        if matrix[line-1][mid] == target:
            return True
        return False

t = Solution()
print(t.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,50]],5))
print(t.searchMatrix([[1]],0))
print(t.searchMatrix([[1]],2))
print(t.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],3))
print(t.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],13))
print(t.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],33))

