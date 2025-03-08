from typing import *


class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n: int = len(palindrome)
        if n == 1:
            return ""
        palindrome: List[str] = list(palindrome)
        npos: int = n // 2 if n % 2 else -1
        for i in range(0, n):
            if palindrome[i] != 'a' and i != npos:
                palindrome[i] = 'a'
                return "".join(palindrome)
        palindrome[-1] = 'b'
        return "".join(palindrome)


def main():
    test = Solution()
    print(test.breakPalindrome("abccba"))
    print(test.breakPalindrome("a"))
    print(test.breakPalindrome("aba"))


if __name__ == "__main__":
    main()
