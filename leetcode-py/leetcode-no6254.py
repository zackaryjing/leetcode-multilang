from configparser import ConfigParser
class Solution2(object):
    def dividePlayers(self, skill):
        """
        :type skill: List[int]
        :rtype: int
        """
        average = sum(skill)/len(skill)*2
        print(average)
        team = []
        copy = skill[:]
        for i in skill:
            if average-i in copy:
                team += [[i,average-i]]
                copy.remove(average - i)
                if i in copy:
                    copy.remove(i)
                else:
                    return -1
        print(team)
        if not len(team) == len(skill)//2:
            return -1
        return int(sum(map(lambda x:x[0]*x[1],team)))

class Solution3:
    def dividePlayers(self, skill: list[int]) -> int:
        average = sum(skill) / len(skill) * 2
        result = 0
        copy = skill[:]
        copy2 = skill[:]
        times = 0
        for i in skill:
            if not average-i in skill:
                return -1
        for i in skill:
            mid = average-i
            if mid in copy and i in copy:
                result += i*(mid)
                copy.remove(mid)
                copy.remove(i)
                times += 1
        if not times == len(skill) // 2:
            return -1
        return int(result)

class Solution:
    def dividePlayers(self, skill: list[int]) -> int:
        skill.sort()
        length = len(skill)
        half = length//2
        average = sum(skill) / half
        for i in range(half):
            if not skill[i] + skill[length-i-1] == average:
                return -1
        result = 0
        for i in range(half):
            result += skill[i] * skill[length-i-1]
        return result


CONFIGFILE = "tests.txt"
config = ConfigParser()
config.read(CONFIGFILE)
h = eval(config.get("threesum",'test3'))

t = Solution()
print(t.dividePlayers([3,2,5,1,3,4]))
print(t.dividePlayers([3,4]))
print(t.dividePlayers([1,1,2,3]))
print(t.dividePlayers([3,2,5,1,3,4]))
print(t.dividePlayers(h))
