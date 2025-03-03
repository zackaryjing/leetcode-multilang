from typing import *
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return len([i for i in details if int(i[11:13]) > 60])

t = Solution()
print(t.countSeniors(["7868190130M7522","5303914400F9211","9273338290F4010"]))
print(t.countSeniors( ["1313579440F2036","2921522980M5644"]))
