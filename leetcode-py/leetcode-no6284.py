class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        word1 = sorted(list(word1))
        word2 = sorted(list(word2))

        diff1 = len(set(word1))
        diff2 = len(set(word2))
        df = diff1 - diff2
        if abs(df) > 2:
            return False



