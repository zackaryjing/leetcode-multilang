class Solution:
    def compress(self, chars: list[str]) -> int:
        if chars == []:
            return []
        res = ""
        current = ""
        last = chars[0]
        for char in chars:
            if char == last:
                # print(1,char)
                current += char
            elif char != last:
                # print(2,char)
                res += last+(str(len(current)) if len(current) != 1 else "")
                current = char

            last = char
        res += last + (str(len(current)) if len(current) != 1 else "")
        del chars[:]
        chars.extend(list(res))
        return len(res)

t = Solution()
print(t.compress(["a","a","b","b","c","c","c"]))
print(t.compress(["a","b","c"]))
print(t.compress([]))
print(t.compress(["a","b","c","a","a","a","a","a","a","a","a","a","a","a","a","a","a","b","c"]))
