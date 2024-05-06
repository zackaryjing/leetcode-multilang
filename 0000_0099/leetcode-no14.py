end = ''
class Solution(object):

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        k = len(strs)
        for i in range(0,k):
            try:
                if k == 1:
                    suit = strs[0]
                elif len(strs[i]) >= len(strs[i+1]):
                    suit = strs[i+1]
                else:
                    suit = strs[0]
            except:
                pass
        def find(strs,suit):
            global end
            end = suit
            k = len(strs)
            # print(strs,"\t",suit,end=" ")
            for i in range(0,k):
                if not(strs[i].startswith(suit)):
                    h = list(suit)
                    try:
                        h.pop()
                    except:
                        return ""
                    suit = ''.join(h)
                    # print(i)
                    find(strs[i:],suit)
            return end
        return find(strs,suit)
t = Solution
print(t.longestCommonPrefix(6,["a"]))