from typing import *
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        # print(n)
        dp = [0] * (n + 1)
        s = " " + s
        for i in range(1,n+1):
            # print(dp)
            minum = dp[i-1] + 1
            record = " "
            for j in dictionary:
                m = len(j)
                if i < m:
                    continue
                if s[i-m+1:i+1] == j:
                    if dp[i-m] < minum:
                        minum = dp[i-m]
                        record = j
            if minum != float('inf'):
                dp[i] = minum
            elif i == 0:
                dp[i] = 0
            else:
                dp[i] = dp[i-1] + 1
            # print(dp)
            # print(record)
        # print(list(s))
        # print("  ",end="")
        # for i in dp:
        #     print(i,end="',' ")
        #
        # print(dp)
        # print(dp)
        return dp[-1]
    
t = Solution()
print(t.minExtraChar("kevlplxozaizdhxoimmraiakbak", ["yv","bmab","hv","bnsll","mra","jjqf","g","aiyzi","ip","pfctr","flr","ybbcl","biu","ke","lpl","iak","pirua","ilhqd","zdhx","fux","xaw","pdfvt","xf","t","wq","r","cgmud","aokas","xv","jf","cyys","wcaz","rvegf","ysg","xo","uwb","lw","okgk","vbmi","v","mvo","fxyx","ad","e"]))
print(t.minExtraChar("leetscode",["leet","code","leetcode"]))
print(t.minExtraChar("sayhelloworld",["hello","world"]))
print(t.minExtraChar("jingjryang",["i","j","ng"]))
print()
print()
print(t.minExtraChar("",[]))
print(t.minExtraChar("",["asdf"]))
print(t.minExtraChar("asdf",[]))





