class Solution:
    def findMinDifference(self, timePoints: list[str]) -> int:
        temp = []
        for i in timePoints:
            h,m = i.split(":")[0],i.split(":")[1]
            temp.append(int(h)*60+int(m))
        temp.sort()
        temp += [temp[0]+1440]
        n = len(temp)
        minum = float("inf")
        # print(temp)
        for j in range(n-1):
            if a := (temp[j+1] - temp[j]) < minum:
                minum = a
        return minum



t = Solution()
print(t.findMinDifference(["00:00","23:59","00:00"]))
print(t.findMinDifference(["23:59","00:00"]))
