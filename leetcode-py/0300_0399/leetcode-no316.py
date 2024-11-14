class Solution3(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        middle = set()
        for i in s:
            middle.add(i)
        return "".join(list(middle))

class Solution2(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        for i in s:
            if not i in result:
                result.append(i)
            else:
                pos = result.index(i)


from collections import defaultdict
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        # 维护一个单调栈来记录结果
        stack = list()
        visit = set()

        # 记录字符出现的次数
        count = defaultdict(int)
        for char in s:
            count[char] = count.get(char, 0) + 1

        for char in s:
            print(char,"*",stack)
            # 1.遍历一个字符，就减1
            count[char] -= 1
            # 2.如果该字符已经访问过，就不处理了
            if char in visit:
                continue
            # 3.如果栈不为空，并且栈顶的元素比当前元素大，就出栈
            while stack and stack[-1] > char:
                print(stack[-1],"***")
                if count[stack[-1]] == 0:
                    break
                candidate = stack.pop()
                visit.remove(candidate)
            stack.append(char)
            visit.add(char)

        return "".join(stack)




t = Solution()

print(t.removeDuplicateLetters("cdeacd"))
# print(t.removeDuplicateLetters("bcabc"))
# print(t.removeDuplicateLetters("cbacdcbc"))
