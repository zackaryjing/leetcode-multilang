class Solution:
    def maxContainers(self, n: int, w: int, maxWeight: int) -> int:
        if n ** 2 * w <= maxWeight :
            return n ** 2
        else:
            return maxWeight // w


def main():
    test = Solution()
    print(test.maxContainers(3, 5, 20))
    print(test.maxContainers(2, 3, 15))


if __name__ == "__main__":
    main()
