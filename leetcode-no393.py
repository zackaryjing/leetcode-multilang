class Solution(object):
    def validUtf8(self, data2):
        """
        :type data: List[int]
        :rtype: bool
        """
        data1 = list(map((lambda x:"%0.8d" %int(bin(x)[2:])),data2))
        signature = []
        middle = []
        print(data1)
        for t in data1:
            if t[0] == '0':
                signature.append([t])
                if middle:
                    signature.append(middle)
                    middle = []
            elif t[0:2] == "10":
                middle.append(t)
            else:
                if middle:
                    signature.append(middle)
                    middle = []
                middle.append(t)
        if middle:
            signature.append(middle)

        def getbytes(first):
            bits = 0
            for i in first:
                if i != '0':
                    bits += 1
                else:
                    break
            return bits

        # length = len(data1)
        # for i in range(length):
        #     if data1[i][0] == '0':
        #         signature.append([t])
        #         if middle:
        #             signature.append(middle)
        #             middle = []
        #     else:
        #         middle.append(data1[i])
        # if middle:
        #     signature.append(middle)

        print(signature)
        for data in signature:
            if len(data)>= 5:
                return False
            if len(data) < 2 and not data[0].startswith('0'):
                return False
            if data[0][0] == '0':
                bits = 1
            else:
                bits = getbytes(data[0])

            if not bits == len(data):
                return False
        return True

t = Solution()
print(t.validUtf8([197,130,1]))
print(t.validUtf8([235,140,4]))
print(t.validUtf8([10]))
print(t.validUtf8([255]))
print(t.validUtf8([237]))
print(t.validUtf8([145]))
print(t.validUtf8([228,189,160,229,165,189,13,10]))

