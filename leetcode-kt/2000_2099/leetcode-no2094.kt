// problem: https://leetcode.cn/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12

package leetcodeNo2094

class Solution {
    fun findEvenNumbers(digits: IntArray): IntArray {
        var cnt = 0
        val reducedDigits = mutableListOf<Int>()
        for (digit in digits) {
            if (((cnt shr (digit * 2)) and 3) < 3) {
                reducedDigits.add(digit)
                cnt += 1 shl (digit * 2)
            }
        }
        val res = hashSetOf<Int>();
        val n = reducedDigits.size
        for (i in 0..<n) {
            if ((reducedDigits[i] and 1) != 1) {
                val first = reducedDigits[i]
                for (j in 0..<n) {
                    if (i != j) {
                        val second = reducedDigits[j]
                        for (k in 0..<n) {
                            val third = reducedDigits[k]
                            if (third != 0 && k != i && k != j) {
                                res.add(first + second * 10 + third * 100)
                            }
                        }
                    }
                }
            }
        }
        return res.toIntArray().sortedArray()
    }
}

fun main() {
    val test = Solution()
    println(test.findEvenNumbers(intArrayOf(2, 1, 3, 0)).joinToString(","))
    println(test.findEvenNumbers(intArrayOf(2, 2, 8, 8, 2)).joinToString(","))
    println(test.findEvenNumbers(intArrayOf(3, 7, 5)).joinToString(","))
}

//
// Created By Zackary At 2025/5/12 12:14
//