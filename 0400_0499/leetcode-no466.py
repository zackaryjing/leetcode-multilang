from typing import *



class Solution2:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        target = s2 * n2
        for i in s2:
            if i not in s1:
                return 0
        pos = 0
        repeat_times = 1
        s1length = len(s1)
        s2length = len(s2)
        # find how many times s1 is needed to make 1 s2
        for i in target:
            while True:
                if s1[pos] == i:
                    break
                else:
                    pos = pos + 1
                    if pos >= s1length:
                        pos %= s1length
                        repeat_times += 1
        if repeat_times > n1:
            return 0
        else:
            return n1 // repeat_times


class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        if n1 == 0:
            return 0
        s1cnt,index,s2cnt = 0,0,0
        recall = dict()
        # 关键是要确保当前字符再s1中出现的位置也和之前一样才能叫循环节
        while True:
            s1cnt += 1
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        s2cnt,index = s2cnt + 1,0
            if s1cnt == n1:
                return s2cnt // n2

            if index in recall:
                s1cnt_prime ,s2cnt_prime = recall[index]
                pre_loop = (s1cnt_prime,s2cnt_prime)
                in_loop = (s1cnt - s1cnt_prime,s2cnt-s2cnt_prime)
                break
            else:
                recall[index] = (s1cnt,s2cnt)

        print("fucking stop it")
        ans = pre_loop[1] + (n1 - pre_loop[0]) // in_loop[0] * in_loop[1]
        rest = (n1 - pre_loop[0]) % in_loop[0]
        for i in range(rest):
            for ch in s1:
                if ch == s2[index]:
                    index += 1
                    if index == len(s2):
                        ans ,index = ans + 1,0
        test = "why dont you fucking stop it?"
        # print(test)
        # print("fucking stop it")
        return ans // n2






t = Solution()
print(t.getMaxRepetitions("aaa",3,"aa",1))
# print(t.getMaxRepetitions("acb",4,"ab",2))
# print(t.getMaxRepetitions("acb",1,"acb",1))



