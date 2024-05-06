ut = [0,1]
for i in range(2,10001):
    # print([i]+[ut[i-j**2]+1 for j in range(1,int(i**0.5)+1)])
    ut.append(min([i]+[ut[i-j**2]+1 for j in range(1,int(i**0.5)+1)]))
print(ut)
class Solution:
    def numSquares(self, n: int) -> int:
        return ut[n]
