class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        if n < 3:
            return False
        start = 0
        end = 0
        for i in range(1,n//3+2):
            for j in range(i+1,(i+2+n)//2):
                # print(num[0:i],num[i:j])
                if num[j:].startswith(str(int(num[0:i]) + int(num[i:j])))\
                        and not ((num[0:i][0] == "0" and len(num[0:i]) != 1 )\
                                  or (num[i:j][0] == "0" and len(num[i:j]) != 1)):
                    start = i
                    end = j
        if start == 0:
            return False
        # print(start,end)
        a = int(num[0:start])
        b = int(num[start:end])
        c = a + b
        test = num[0:start] + num[start:end] + str(c)
        valid = 1
        # print(test)
        while len(test) < n:
            # print(test)
            # print(a,b,c)
            a,b,c = b,c,b+c
            test += str(c)
            if not num.startswith(test):
                return False
        if len(test) > n:
            return False
        return True


t = Solution()
print(t.isAdditiveNumber("199001200"))
print(t.isAdditiveNumber("0"))
print(t.isAdditiveNumber("0235813"))
print(t.isAdditiveNumber("111"))
print(t.isAdditiveNumber("112358"))
print(t.isAdditiveNumber("112358"))
print(t.isAdditiveNumber("11233458"))
print(t.isAdditiveNumber("199100199"))
print(t.isAdditiveNumber("199111992"))
