class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = [i for i in map(int,version1.split("."))]
        v2 = [j for j in map(int,version2.split("."))]
        difference = abs(len(v1)-len(v2))
        needappend = v1 if len(v1) < len(v2) else v2
        needappend.extend([0]*difference)
        length = max(len(v1),len(v2))
        for i in range(length):
            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1
        return 0


t = Solution()
print(t.compareVersion("1.12.01.1","1.12.01"))
print(t.compareVersion("1.12.01.0.01","1.12.01.0.2"))
