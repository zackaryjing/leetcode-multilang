class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        database = ["qQwWeErRtTyYuUiIoOpP","aAsSdDfFgGhHjJkKlL","zZxXcCvVbBnNmM"]
        data = "qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM"
        for word in words:
            ok = 1
            initial = data.index(word[0])
            if initial < 19:
                wordbank = 0
            elif initial < 37:
                wordbank = 1
            else:
                wordbank = 2
            for letter in word:
                if not letter in database[wordbank]:
                    ok = 0
                    break
            if ok:
                result.append(word)
        return result

t = Solution()
print(t.findWords(["Qwe","wer","efv","asd","xcv","rfv"]))