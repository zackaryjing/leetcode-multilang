'''
无时无刻不被leetcode提醒，我其实是多么的菜。
永远被超时和写不出来折磨。。。
最后是看了题解写的解法。
'''

class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        cs = set(s)
        cd = set(''.join(wordDict))
        # print(cs)
        # print(cd)
        if cs - cd != set():
            return False
        def dfs(currents: str):
            print(currents)
            if currents == "":
                return True
            for i in wordDict:
                if currents.startswith(i):
                    if dfs(currents[len(i):]):
                        return True
        a = dfs(s)
        return a if a else False


class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        dp = [True]
        for i in range(len(s)):
            for j in range(len(s),i,-1):




t = Solution()
print(t.wordBreak("leetcode",["leet","code"]))
print(t.wordBreak("applepenapple",["apple", "pen"]))
print(t.wordBreak("catsandog",["cats", "dog", "sand", "and", "cat"]))
print(t.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]))
print(t.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",["aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"]))

