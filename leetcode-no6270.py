class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        if (s.count('a') or s.count('b') or s.count('c')) < k:
            return -1
        firstlist = []
        secondlist = []
        alist = blist = [0,0,0]
        length = len(s)
        for i in range(length):
            alist[s[i].index("abc")] += 1
            firstlist.append(alist)
        for j in range(length-1,-1,-1):
            blist[s[j].index("abc")] += 1
            secondlist.append(alist)

class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        if (s.count('a') or s.count('b') or s.count('c')) < k:
            return -1
        news = s*2
        length = len(news)
        minum = length
        start = length//2
        for i in range(start,length+1):
            mid = news[start:i]
            if mid.count("a") >= k and mid.count("b") >= k and mid.count("c") >= k:
                end = i
                break
        for i in range(start,-1,-1):
            mid = news[i:start]
            if mid.count("a") >= k and mid.count("b") >= k and mid.count("c") >= k:
                begin = i
                break
        for j in range(begin,end):
            for t in range(j,end):
                mid = news[j:t]
                if mid.count("a") >= k and mid.count("b") >= k and mid.count("c") >= k:
                    if (t-j) < minum:
                        minum = t-j
        return minum

t = Solution()
print(t.takeCharacters("aabaaaacaabc",2))
print(t.takeCharacters("c",2))
print(t.takeCharacters("a",2))
