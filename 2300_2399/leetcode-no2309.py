class Solution:
    def greatestLetter(self, s: str) -> str:
        expect = []
        res = []
        for i in s:
            # print(expect)
            if i in expect:
                res.append(i.upper())
            else:
                expect.append(i.lower() if i.isupper() else i.upper())
        res.sort()
        return "" if not res else res[-1]

t = Solution()
print(t.greatestLetter("lEeTcOdE"))
print(t.greatestLetter("arRAzFif"))
