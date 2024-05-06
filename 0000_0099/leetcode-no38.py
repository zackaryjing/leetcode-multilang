from collections import defaultdict
data = defaultdict(int)
data[1] = "1"
class Solution:
    def countAndSay(self, n: int) -> str:
        def dfs(n):
            if n in data.keys():
                return data[n]
            else:
                last = dfs(n-1)
                current = last[0]
                times = 0
                ans = ""
                for i in last:
                    if i == current:
                        times += 1
                    else:
                        ans += "%d%s" %(times,current)
                        current = i
                        times = 1
                ans += "%d%s" %(times,current)
                data[n] = ans
                return ans
        return dfs(n)

t = Solution()
for i in range(1,10):
    print(t.countAndSay(i))


