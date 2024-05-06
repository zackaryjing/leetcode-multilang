class Solution(object):
    def convertToTitle(self, columnNumber):   #终于通过了，尝试优化一下吧
        """
        :type columnNumber: int
        :rtype: str
        """
        resultlist = []
        data = {0:"Z",1:"A",2:"B",3:"C",4:"D",5:"E",\
        6:"F",7:"G",8:"H",9:"I",10:"J",11:"K",\
                12:"L",13:"M",14:"N",15:"O",16:"P",\
                17:"Q",18:"R",19:"S",20:"T",21:"U",\
                22:"V",23:"W",24:"X",25:"Y",26:"Z"}
        while True:
            middle = columnNumber%26
            special = 1 if middle == 0 else 0
            columnNumber = columnNumber//26 - special
            resultlist.append(data[middle])
            if columnNumber == 0:
                break
        resultlist.reverse()
        return ''.join(resultlist)


class Solution(object):
    def convertToTitle(self, columnNumber):   #终于通过了，尝试优化一下吧
        """
        :type columnNumber: int
        :rtype: str
        """
        result = ""
        data = {0:"Z",1:"A",2:"B",3:"C",4:"D",5:"E",\
        6:"F",7:"G",8:"H",9:"I",10:"J",11:"K",\
                12:"L",13:"M",14:"N",15:"O",16:"P",\
                17:"Q",18:"R",19:"S",20:"T",21:"U",\
                22:"V",23:"W",24:"X",25:"Y",26:"Z"}
        while True:
            middle = columnNumber%26
            special = 1 if middle == 0 else 0
            columnNumber = columnNumber//26 - special
            result = data[middle] + result
            if columnNumber == 0:
                break
        return ''.join(result)


t = Solution()
print(t.convertToTitle(453))

# t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# for i in range(0,26):
#     print(str(i+1)+':'+'"'+t[i]+'"'+",",end='')