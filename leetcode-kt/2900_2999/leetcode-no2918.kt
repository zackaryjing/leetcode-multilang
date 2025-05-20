// problem: https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10

package leetcodeNo2918
class Solution {
    fun minSum(nums1: IntArray, nums2: IntArray): Long {
        val res = 0L
        var sumFirst = 0L
        var sumSecond = 0L
        var zeroCntFirst = 0L
        var zeroCntSecond = 0L
        for (num in nums1) {
            sumFirst += num
            if (num == 0) {
                zeroCntFirst += 1
                sumFirst += 1
            }
        }
        for (num in nums2) {
            sumSecond += num
            if (num == 0) {
                zeroCntSecond += 1
                sumSecond += 1
            }
        }

        if (sumSecond < sumFirst) {
            sumSecond = sumFirst.also { sumFirst = sumSecond }
            zeroCntSecond = zeroCntFirst.also { zeroCntFirst = zeroCntSecond }
        }

//        println(zeroCntSecond)
//        println("$sumFirst $sumSecond")

        if (zeroCntFirst == 0L && sumSecond != sumFirst) {
            return -1
        } else {
            return sumSecond
        }
    }
}

fun main() {
    val test = Solution()
    println(test.minSum(listOf(0, 7, 28, 17, 18).toIntArray(), listOf(1, 2, 6, 26, 1, 0, 27, 3, 0, 30).toIntArray()))
    println(test.minSum(listOf(3, 2, 0, 1, 0).toIntArray(), listOf(6, 5, 0).toIntArray()))
    println(test.minSum(listOf(2, 0, 2, 0).toIntArray(), listOf(1, 4).toIntArray()))
}

//
// Created By Zackary At 2025/5/10 21:07
//