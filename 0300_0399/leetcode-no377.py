from math import factorial
from collections import defaultdict
class Solution2:
    '''WTL Solution'''
    def combinationSum4(self, nums: list[int], target: int) -> int:
        nums.sort()
        res = 0
        def dfs(combin,candidate,targetnum):
            nonlocal res
            if targetnum < 0:
                return
            if targetnum == 0:
                print(combin)
                data = defaultdict(int)
                for i in combin:
                    data[i] += 1
                values = list(data.values())
                total = sum(values)
                n = len(values)
                mid = 1
                for j in range(n-1):
                    j = values[j]
                    mid *= (factorial(total)//(factorial(j)*factorial(total-j)))
                    total -= j
                res += mid
            for i in range(len(candidate)):
                dfs(combin+[candidate[i]],candidate[i:],targetnum-candidate[i])

        dfs([],nums,target)
        return res

class Solution:
    def combinationSum4(self, nums: list[int], target: int) -> int:
        n = target
        data = [0] * (n + 1)
        data[0] = 1
        for i in range(n+1):
            for j in nums:
                if i - j >= 0:
                    data[i] += data[i-j]
        return data

t = Solution()
print(t.combinationSum4([1,2,3],4))
print(t.combinationSum4([9],3))
print(t.combinationSum4([10,20,30,40,50,60,70,80,90,100,110,111,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990],999))
