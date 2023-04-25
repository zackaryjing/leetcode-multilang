class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        length = len(gas)
        difference = [gas[i] - cost[i] for i in range(length)]
        print(difference)
        i = 0
        while i < length:
            sum = 0
            k = 1
            for j in range(i,length):
                sum += difference[j]
                if sum < 0:
                    k = 0
                    i = j
                    break
            if k:
                for t in range(0,i):
                    sum += difference[t]
                    if sum < 0:
                        i = j
                        break
            print(sum)
            if not sum < 0:
                return i
            i += 1

        return -1
t = Solution()
# print(t.canCompleteCircuit([1,2,3,4,5],[3,4,5,1,2]))
print(t.canCompleteCircuit([67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66],\
[27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]))
