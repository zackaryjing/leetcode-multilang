class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def listmul(list1,list2):
            result = []
            for i in list1:
                for j in list2:
                    result.append(i+j)
            return result
        data = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],\
                '5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],
                '8':['t','u','v'],'9':['w','x','y','z']}
        end = ['']
        for i in digits:
            end = listmul(end,data[i])
        if end == ['']:
            return []
        else:
            return end
t = Solution()
print(t.letterCombinations("23"))
