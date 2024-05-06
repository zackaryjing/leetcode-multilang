import re
from itertools import combinations


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        # 暴力解法
        # 定义检查其中是否有重复字符的函数
        def check(x):
            each = []
            for i in x:
                if not (i in each):
                    each.append(i)
            if len(each) < len(x):
                return False
            return True
        sons = []
        # 定义分割字符串函数
        def substr(floor):
            for i in range(length-floor):
                sons.append(s[i:i+floor+1])
            if floor < length:
                return substr(floor+1)
            return
        substr(0)
        goodsons = []
        for son in sons:
            if check(son):
                goodsons.append(son)
        try:
            return len(max(goodsons,key=len))
        except:
            return 0

class Solution2(object): # 有亿点点问题，甩锅split函数
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 获得重复的元素
        repeat = []
        if s != '' and s.count(s[0])==len(s) :
            return 1
        for i in s:
            if s.count(i) > 1:
                if not i in repeat:
                    repeat.append(i)
        if repeat == []:
            return len(s)
        fractions = []
        for i in repeat:
            fractions.extend(s.split(i))
        for i in range(fractions.count('')):
            fractions.remove('')
        def check(x):
            each = []
            for i in x:
                if not (i in each):
                    each.append(i)
            if len(each) < len(x):
                return False
            return True
        leftones = []
        for i in fractions:
            if check(i):
                leftones.append(i)
        print(leftones)
        try :
            return max(leftones,key=len),len(max(leftones,key=len))+1
        except:
            return 0


#重新定义一个类似split的函数
def susplit(string,node):
    index = []
    result = []
    length = len(string)
    for i in range(length):
        if string[i] == node:
            index.append(i)
    for i in combinations(index,2):
        result.append(string[i[0]:i[1]])
    return result

# print(susplit("aaaaaa","a"))
class Solution3(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        #获得重复的元素
        repeat = []
        if s != '' and s.count(s[0])==len(s) :
            return 1
        for i in s:
            if s.count(i) > 1:
                if not i in repeat:
                    repeat.append(i)
        if repeat == []:
            return len(s)
        fractions = []
        for i in repeat:
            fractions.extend(susplit(s,i))
        for i in range(fractions.count('')):
            fractions.remove('')
        def check(x):
            each = []
            for i in x:
                if not (i in each):
                    each.append(i)
            if len(each) < len(x):
                return False
            return True
        leftones = []
        for i in fractions:
            if check(i):
                leftones.append(i)
        print(leftones)
        try :
            return max(leftones,key=len),len(max(leftones,key=len))
        except:
            return 0

#看完视频，打算按收缩窗口来写
class Solution4(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        total = 0
        current = ''
        length = len(s)
        i = 0
        while i < length:
            now = s[i]
            if not now in current:
                current += now
            else:
                currentlen = len(current)
                if total < currentlen:
                    total = currentlen
                i = i-currentlen+current.index(now)
                current = ''
            i += 1
        if total < len(current):
            total = len(current)
        return total



# s = "abcdefghijk"
# b = re.split('a{2}',"aaabcdaaefghijk")
# print(b)

t = Solution4()
print(t.lengthOfLongestSubstring("asdfadgasdas"))


