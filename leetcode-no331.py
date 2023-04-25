class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        alist = preorder.split(",")
        stack = [0]
        for i in alist:
            if stack:
                last = stack.pop()
                if last == 2:
                    stack.append(1)
                if i != "#":
                    stack.append(2)
            else:
                return False
        if not stack:
            return True
        return False



t = Solution()
print(t.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#,#"))


