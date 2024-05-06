class Solution2:
    def numRabbits(self, answers: list[int]) -> int:
        answers.sort()
        current = -1
        times = 1
        total = answers.count(0)
        del answers[:total]
        for i in answers:
            # print(i)
            # print(times,"()")
            if i != current:
                times = 1
                current = i
                total += i + 1
            elif times > current + 1:
                # print("*")
                total += i + 1
                times = 1
            else:
                times += 1
        if times > current + 1:
            total += i + 1
        return total

class Solution:
    def numRabbits(self, answers: list[int]) -> int:
        answers.sort()
        current = -1
        times = 1
        total = answers.count(0)
        del answers[:total]
        for i in answers:
            if i != current or times >= current + 1:
                print(i,current,times)
                total += i + 1
                times = 1
                current = i
            else:
                times += 1
        if times > current + 1:
            total += i + 1
        return total




t = Solution()
print(t.numRabbits([1,1,2]))
print(t.numRabbits([10,10,10]))
print(t.numRabbits([1,0,1,0,0]))
print(t.numRabbits([0,0,1,1,1]))
print(t.numRabbits([2,1,2,2,2,2,2,2,1,1]))



