class Solution(object):
    def canMeasureWater(self, jug1Capacity, jug2Capacity, targetCapacity):
        """
        :type jug1Capacity: int
        :type jug2Capacity: int
        :type targetCapacity: int
        :rtype: bool
        """
        def gcd(m,n):
            while m%n != 0:
                m,n = n,m%n
            return n
        if targetCapacity > jug1Capacity+jug2Capacity:
            print(1)
            return False
        return targetCapacity%gcd(jug2Capacity,jug1Capacity) == 0

t = Solution()
print(t.canMeasureWater(3,5,4))
print(t.canMeasureWater(2,6,5))
print(t.canMeasureWater(2,6,4))
print(t.canMeasureWater(4,6,8))
