class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        sentence = sentence.split()
        if not sentence:
            return True
        begin = sentence[0][0]
        end = sentence[-1][-1]
        if not begin == end:
            return False
        for i in sentence:
            if not i[0] == begin:
                return False
            else:
                begin = i[-1]
        return True

t = Solution()
print(t.isCircularSentence(""))