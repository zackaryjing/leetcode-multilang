class Solution2:
    def cycleLengthQueries(self, n: int, queries: list[list[int]]) -> list[int]:
        def getlevel(num):
            times = 0
            for i in range(n+1):
                times += 1
                if num < 2**i:
                    break
            return times - 2
        print(getlevel(7))
        print("#"*40)
        res = []
        for query in queries:
            first = query[0]
            second = query[1]
            firstlevel = getlevel(query[0])
            secondlevel = getlevel(query[1])
            if first < second:
                firstlevel,secondlevel = secondlevel,firstlevel
                first,second = second,first
            print(firstlevel,secondlevel)
            leveldifference = abs(firstlevel-secondlevel)
            first -= 2 ** firstlevel
            second -= 2 ** secondlevel
            for i in range(leveldifference):
                first //= 2
            left = 0
            right = 2 ** secondlevel
            mid = (left + right) // 2
            times = 0
            if first == second:
                res.append(leveldifference + 1)
            else:
                for i in range(secondlevel+1):
                    times += 1
                    if left < second <= first <= mid:
                        right = mid
                        mid = (left + right) // 2
                    elif mid < second <= first <= right:
                        left = mid
                        mid = (left + right) // 2
                    else:
                        break
                print(leveldifference)
                print(secondlevel)
                print(times)
                print("*"*40)
                res.append((secondlevel-times+1)*2+leveldifference+1)
        return res

class Solution:
    def cycleLengthQueries(self, n: int, queries: list[list[int]]) -> list[int]:
        def getlevel(num):
            times = 0
            for i in range(n+1):
                times += 1
                if num < 2**i:
                    break
            return times - 2
        print(getlevel(7))
        print("#"*40)
        res = []
        for query in queries:
            first = query[0]
            second = query[1]
            firstlevel = getlevel(query[0])
            secondlevel = getlevel(query[1])
            if first < second:
                firstlevel,secondlevel = secondlevel,firstlevel
                first,second = second,first
            print(firstlevel,secondlevel)
            leveldifference = abs(firstlevel-secondlevel)
            first -= 2 ** firstlevel
            second -= 2 ** secondlevel
            for i in range(leveldifference):
                first //= 2
            times = 0
            print("f",first,"s",second)
            if first == second:
                res.append(leveldifference + 1)
            else:
                for i in range(secondlevel+1):
                    times += 1
                    if first != second:
                        first //= 2
                        second //= 2
                    else:
                        break
                print(leveldifference)
                print(secondlevel)
                print(times)
                print("*"*40)
                res.append((times-1)*2+leveldifference+1)
        return res

from math import log2
class Solution:
    def cycleLengthQueries(self, n: int, queries: list[list[int]]) -> list[int]:
        res = []
        for query in queries:
            first = query[0]
            second = query[1]
            level1 = int(log2(first))
            level2 = int(log2(second))
            difference = abs(level1 - level2)
            if level2 > level1:
                first,second = second,first
            first //= 2**difference
            times = 0
            while first != second:
                first //= 2
                second //= 2
                times += 1
            res.append(times * 2 + difference + 1)
        return res


t = Solution()
print(t.cycleLengthQueries(3,[[5,3],[4,7],[2,3]]))
print(t.cycleLengthQueries(2,[[1,2]]))
print(t.cycleLengthQueries(5,[[11,2]]))
print(t.cycleLengthQueries(4,[[14,13]]))
print(t.cycleLengthQueries(4,[[9,5]]))



