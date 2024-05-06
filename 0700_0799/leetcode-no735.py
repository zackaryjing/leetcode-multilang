class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        stack = []
        i = 0
        n = len(asteroids)
        while i < n:
            if len(stack) > 0 and asteroids[i] < 0:
                if stack[-1] > 0 and asteroids[i] < 0 and stack[-1] > -asteroids[i]:
                    i += 1
                # if stack[-1] < 0 and asteroids[i] > 0 and -stack[-1] < asteroids[i]:
                #     i += 1
                elif stack[-1] > 0 and asteroids[i] < 0 and stack[-1] < -asteroids[i]:
                    stack.pop()
                # elif stack[-1] < 0 and asteroids[i] > 0 and -stack[-1] < asteroids[i]:
                #     stack.pop()
                elif stack[-1] == -asteroids[i]:
                    stack.pop()
                    i += 1
                else:
                    stack.append(asteroids[i])
                    i += 1
            else:
                stack.append(asteroids[i])
                i += 1
        return stack


t = Solution()
print(t.asteroidCollision([5,10,-5]))
print(t.asteroidCollision([-2,-1,1,2]))
print(t.asteroidCollision([8,-8]))
print(t.asteroidCollision([10,2,-5]))













# class Solution:
#     def asteroidCollision(self, asteroids: list[int]) -> list[int]:
#         stack = []
#         i = 0
#         n = len(asteroids)
#         while i < n:
#             print(i)
#             while len(stack) > 0 and ((stack[-1] < 0 and asteroids[i] > 0) or (asteroids[i] < 0 and stack[-1] > 0)):
#                 print(stack,i)
#                 if (stack[-1] > 0 and asteroids[i] < 0):
#                     if (a := stack.pop()) > -asteroids[i]):
#                         stack.append(a)
#                         i += 1
#                     else:
#                         stack.append(asteroids[i])
#                     stack.append(a if (a := stack.pop()) > -asteroids[i] else asteroids[i])
#                     i += 1
#                     print("t")
#                 elif (stack[-1] < 0 and asteroids[i] > 0):
#                     stack.append(-a if (a := -stack.pop()) > asteroids[i] else asteroids[i])
#                     i += 1
#                     print("k")
#                 else:
#                     stack.append(asteroids[i])
#                     print("v")
#             else:
#                 stack.append(asteroids[i])
#             i += 1
#         return stack

# t = Solution()
# print(t.asteroidCollision([5,10,-5]))
# print(t.asteroidCollision([10,2,-5]))


