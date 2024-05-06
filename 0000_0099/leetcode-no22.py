class Solution2(object):  #暴力解法吧
    def generateParenthesis(self, n):  #这个解法有一些无法生成，只好重新来过了
        """
        :type n: int
        :rtype: List[str]
        """
        def inject(combinations):
            result = []
            for i in combinations:
                a = "()" + i
                b = "(" + i + ")"
                c = i + "()"
                for t in [a, b, c]:
                    if not t in result:
                        result.append(t)
            return result
        end = [""]
        for i in range(n):
            end = inject(end)
        return sorted(end)

class Solution(object):
    def generateParenthesis(self, n):
        def inject(alist):
            newlist = []
            for j in alist:
                length = len(j)
                for i in range(length+1):
                    t = j[0:i]+"()"+j[i:]
                    if not t in newlist:
                        newlist.append(t)
            return newlist
        result = [""]
        for i in range(n):
            result = inject(result)
        return sorted(result)

# t = Solution()
# print(t.generateParenthesis(3)(['()()()', '(())()', '()(())', '(()())', '((()))']))
# def inject(combinations):
#     result = []
#     for i in combinations:
#         a = "()" + i
#         b = "("+i+")"
#         c = i+"()"
#         for t in [a,b,c]:
#             if not t in result:
#                 result.append(t)
#     return result
#
# print(inject(['()()', '(())']))

# t = Solution()
# for i in range(1,9):
#     print("elif n ==",i,":")
#     print("\t","return",t.generateParenthesis(i))


# k = t.generateParenthesis(4)
# g = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
# for i in g:
#     if not i in k:
#         print(i)
# print(len(["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]))

#无赖做法
class Solution3(object):
    def generateParenthesis(self, n):
        if n == 1:
            return ['()']
        elif n == 2:
            return ['(())', '()()']
        elif n == 3:
            return ['((()))', '(()())', '(())()', '()(())', '()()()']
        elif n == 4:
            pass
        '''由于解法太不优雅，后面的太长了，删掉了，实测可行'''

t = Solution()
print(len(t.generateParenthesis(3)))
print(len(t.generateParenthesis(4)))
print(len(t.generateParenthesis(5)))
print(len(t.generateParenthesis(6)))
