class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        sgn = ''
        if numerator*denominator < 0:
            sgn = '-'
        numerator = abs(numerator)
        denominator = abs(denominator)
        if numerator % denominator == 0:
            return '-'+str(numerator//denominator)
        remains = []
        result = []
        repeat = []
        nonrepeat = []
        while True:
            Remain = numerator % denominator
            if Remain == 0:
                break
            if Remain in remains:
                # print(Remain,"++")
                result.append(numerator // denominator)
                repeat = result[remains.index(Remain)+1:]
                nonrepeat = result[1:remains.index(Remain)+1]
                # print(result)
                break
            remains.append(Remain)
            result.append(numerator // denominator)
            numerator = 10*Remain
        result.append(numerator // denominator)
        if repeat:
            return sgn+str(result[0])+'.'+''.join(map(str,nonrepeat))+'('+''.join(map(str,repeat))+')'
        return sgn+str(result[0])+'.'+''.join(map(str,result[1:]))

t = Solution()
print(t.fractionToDecimal(1,2))
print(t.fractionToDecimal(2,3))
print(t.fractionToDecimal(7,8))
print(t.fractionToDecimal(90,8))
print(t.fractionToDecimal(17,11))
print(t.fractionToDecimal(-50,8))
print(t.fractionToDecimal(-2147483648,1))
