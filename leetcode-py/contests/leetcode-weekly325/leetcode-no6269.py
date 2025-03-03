class Solution:
    def closetTarget(self, words: list[str], target: str, startIndex: int) -> int:
        if not target in words:
            return -1
        else:
            a = abs(words.index(target)-startIndex)
            b = abs((words*2).index(target)-(len(words)+startIndex+1))
        return min(a,b)

class Solution:
    def closetTarget(self, words: list[str], target: str, startIndex: int) -> int:
        if not target in words:
            return -1
        else:
            length = len(words)
            k = 0
            j = 0
            a = b = startIndex
            la = lb = 0
            while True:
                if words[a] == target:
                    k += 1
                if words[b] == target:
                    j += 1
                if not k:
                    a -= 1
                    la += 1
                    if a < -length:
                        a = length - 1
                if not j:
                    b += 1
                    lb += 1
                    if b >= length:
                        b = 0
                if k and j:
                    break
            return min(la,lb)
t = Solution()
print(t.closetTarget(["hello","i","am","leetcode","hello"],"hello",1))
print(t.closetTarget(["a","b","leetcode"],"leetcode",0))
print(t.closetTarget(["i","eat","leetcode"],"ate",0))
print(t.closetTarget(["hsdqinnoha","mqhskgeqzr","zemkwvqrww","zemkwvqrww","daljcrktje","fghofclnwp","djwdworyka","cxfpybanhd","fghofclnwp","fghofclnwp"],"zemkwvqrww",8))
