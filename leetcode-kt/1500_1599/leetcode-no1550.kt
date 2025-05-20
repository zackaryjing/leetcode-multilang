// problem: https://leetcode.cn/problems/three-consecutive-odds/?envType=daily-question&envId=2025-05-11

package leetcodeNo1550

class Solution {
    fun threeConsecutiveOdds(arr: IntArray): Boolean {
        val n = arr.size;
        var i = 2
        while (i < n) {
            if (arr[i - 2] and 1 == 1) {
                if (arr[i - 1] and 1 == 1) {
                    if (arr[i] and 1 == 1) {
                        return true
                    } else {
                        i += 3
                    }
                } else {
                    i += 2;
                }
            } else {
                i += 1;
            }
        }
        return false
    }
}

fun main() {
    val test = Solution()
    println(test.threeConsecutiveOdds(listOf<Int>(2, 6, 4, 1).toIntArray()))
    println(test.threeConsecutiveOdds(listOf<Int>(1, 2, 34, 3, 4, 5, 7, 23, 12).toIntArray()))
}

//
// Created By Zackary At 2025/5/11 14:47
//