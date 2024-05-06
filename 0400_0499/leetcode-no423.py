from collections import defaultdict
class Solution:
    def originalDigits(self, s: str) -> str:
        data = defaultdict(int)
        res = ""
        for i in s:
            data[i] += 1
        res += data["z"] * "0"
        res += data["w"] * "2"
        res += data["u"] * "4"
        res += (data["f"] - data["u"]) * "5"
        res += data["x"] * "6"
        res += data["g"] * "8"
        res += (data["o"] - data["w"] - data["u"] - data["z"]) * "1"
        res += (data["h"] - data["g"]) * "3"
        res += (data["s"] - data["x"]) * "7"
        res += (data["i"] - data["x"] - data["g"] - data["f"] + data["u"]) * "9"
        return "".join(sorted(list(res)))
t = Solution()
print(t.originalDigits("owoztneoer"))
print(t.originalDigits("fviefuro"))
print(t.originalDigits("esnve"))


