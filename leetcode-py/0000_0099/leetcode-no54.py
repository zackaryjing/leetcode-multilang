class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        depth = 0
        a = len(matrix)
        b = len(matrix[0])
        res = []
        # if a == 1:
        #     return matrix[0]
        # if b == 1:
        #     return [i[0] for i in matrix]
        for i in range((min(a,b)+ 1) // 2):
            times1 = b - 1 - 2 * depth
            times2 = a - 1 - 2 * depth
            # print(times1,times2)
            if times1 == 0:
                res.extend([i[b - depth - 1] for i in matrix[depth:depth+times2+1]])
                break
                # print(6)
            if times2 == 0:
                res.extend(matrix[depth][depth:depth+times1+1])
                break
                # print(5)

            for j in range(times1):
                res.append(matrix[depth][depth + j])
            # print(res,1)
            for k in range(times2):
                res.append(matrix[depth + k][b - depth - 1])
            # print(res,2)
            for l in range(times1):
                res.append(matrix[a - depth - 1][b - 1 - depth - l])
            # print(res,3)
            for m in range(times2):
                res.append(matrix[a - 1 - depth - m][depth])
            # print(res,4)
            depth += 1
        # if a == b and a % 2 == 1:
        #     res.append(matrix[a//2][a//2])
        return res


class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        depth = 0
        a = len(matrix)
        b = len(matrix[0])
        res = []
        for i in range((min(a, b) + 1) // 2):
            times1 = b - 1 - 2 * depth
            times2 = a - 1 - 2 * depth
            if times1 == 0:
                res.extend([i[b - depth - 1] for i in matrix[depth:depth + times2 + 1]])
                break
            if times2 == 0:
                res.extend(matrix[depth][depth:depth + times1 + 1])
                break
            for j in range(times1):
                res.append(matrix[depth][depth + j])
            for k in range(times2):
                res.append(matrix[depth + k][b - depth - 1])
            for l in range(times1):
                res.append(matrix[a - depth - 1][b - 1 - depth - l])
            for m in range(times2):
                res.append(matrix[a - 1 - depth - m][depth])
            depth += 1
        return res


t = Solution()
# print(t.spiralOrder([[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]))
print(t.spiralOrder([[6]]))
# print(t.spiralOrder([[6],[7],[8],[9],[10]]))
# print(t.spiralOrder([[6,9,7]]))
# print(t.spiralOrder([[1,2],[3,4]]))
# print(t.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))
print(t.spiralOrder([[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15]]))
# print(t.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]))
# print(t.spiralOrder([[1,2,3],[4,5,6],[7,8,9],[10,11,12]]))
print(t.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))
