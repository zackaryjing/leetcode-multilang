class Solution2(object):
    def combinationSum(self, candidates, target):   #自己的代码写的太糟糕了
        """                                         #打算学习一下正规的回溯算法
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort(reverse=True)
        total = []
        cache = []
        def getMinued(minueds,tar):
            print("*"*40)
            print((minueds,tar,cache,total))
            if minueds==[]:
                print("yes")
                cache.pop()
                return
            length = len(minueds)
            for i in range(0,length):
                print(i)
                minued = minueds[i]
                print("minued:",minued)
                difference = tar
                while minued <= difference:
                    difference = difference - minued
                    cache.append(minued)
                    if difference == 0:
                        total.append(cache[:])
                        print(cache)
                getMinued(minueds[i+1:],difference)
            return
        getMinued(candidates,target)
        return total


#re完了别人的代码，感觉自己又可以了，重新写吧
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        candidates.sort(reverse=True)
        def dfs(target,combine,id):
            print((id,target))
            if id == len(candidates):
                return
            if target == 0:
                if not combine in ans:
                    ans.append(combine)
            dfs(target,combine,id+1)
            if target - candidates[id] >= 0:
                dfs(target-candidates[id],combine+[candidates[id]],id)
        dfs(target,[],0)
        return ans



t = Solution()
print("the end is:",t.combinationSum([2,3,6,7],7))

