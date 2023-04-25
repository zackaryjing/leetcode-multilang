class Solution:
    def simplifyPath(self, path: str) -> str:
        processedpath = path.split("/")
        for i in range(processedpath.count('')):
            processedpath.remove('')
        res = []
        for i in range(len(processedpath)):
            if processedpath[i] == "..":
                if len(res) != 0:
                    res.pop()
            elif processedpath[i] != ".":
                res.append(processedpath[i])
        res = '/'.join(res)
        return '/'+res



t = Solution()
print(t.simplifyPath("/home/"))
print(t.simplifyPath("/../"))
print(t.simplifyPath("/home//foo/"))
print(t.simplifyPath("/home///foo/"))
print(t.simplifyPath("/a/./b/../../c/"))
