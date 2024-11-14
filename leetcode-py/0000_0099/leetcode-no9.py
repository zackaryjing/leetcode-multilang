def isPalindrome(x):
    """
    :type x: int
    :rtype: bool
    """
    k = list(str(x))
    b = k[:]
    k.reverse()
    print(k == b)
print(isPalindrome(123))