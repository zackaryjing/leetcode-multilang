from typing import *
from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        cnt = defaultdict(int)
        cpdomains = list(map(lambda x:[int((a:=x.split(' '))[0]),a[1].split('.')],cpdomains))
        for times,domains in cpdomains:
            for i in range(len(domains)):
                cnt['.'.join(domains[i:])] += times
        return ["%s %s" %(val,key) for key,val in cnt.items()]

t = Solution()
print(t.subdomainVisits(["9001 discuss.leetcode.com"]))
print(t.subdomainVisits(["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]))

