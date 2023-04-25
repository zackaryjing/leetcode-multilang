class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        alist = []
        dic = {"(":")","[":"]","{":"}"}
        for i in s:
            if i in "([{" :
                alist.append(i)

            if i in ")]}" :
                try:
                    k = alist.pop()
                except:
                    return False
                if i != dic[k]:
                    return False
        if alist == []:
            return True
        else :
            return False

t=Solution
if t.isValid(6,"()[]{}"):
    print("yes")

