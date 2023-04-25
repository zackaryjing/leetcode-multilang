class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        def change(string):
            length = len(string)
            num = 0
            for i in range(length-1,-1,-1):
                num += (ord(string[i])-48)*10**(length-i-1)
            print(num)
            return num
        return str(change(num1)*change(num2))


class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        def change(string):
            string = [i for i in reversed(list(string))]
            nums = 0
            for i in range(len(string)):
                nums+= (ord(string[i])-48)*10**i
            return nums
        return str(change(num1)*change(num2))

t = Solution()
print(t.multiply("123","456"))