// problem: https://leetcode.cn/problems/duplicate-zeros/?envType=problem-list-v2&envId=3rBpGyas

package leetcodeNo1089

class Solution {
    fun duplicateZeros(arr: IntArray): Unit {
        val n = arr.size;
        var end = n - 1;
        var endByZero = false;
        for (i in 0..<n) {
            if (arr[i] == 0) {
                end--;
            }
            if (end <= i) {
                if (end < i) {
                    endByZero = true;
                }
                break;
            }
        }
        var cur = n - 1
        if (endByZero) {
            arr[cur--] = 0
        }
        for (i in end downTo 0) {
            arr[cur--] = arr[i]
            if (arr[i] == 0) {
                arr[cur--] = 0;
            }
        }
    }
}

fun main() {
    val test = Solution()
    val t1 = intArrayOf(1, 0, 2, 3, 0, 4, 5, 0)
    val t2 = intArrayOf(1, 2, 3)
    val t3 = intArrayOf(8, 4, 5, 0, 0, 0, 0, 7)
    val t4 = intArrayOf(1, 5, 2, 0, 6, 8, 0, 6, 0)
    test.duplicateZeros(t1)
    test.duplicateZeros(t2)
    test.duplicateZeros(t3)
    test.duplicateZeros(t4)
    println(t1.joinToString())
    println(t2.joinToString())
    println(t3.joinToString())
    println(t4.joinToString())
}

//
// Created By Zackary At 10/30/25 19:14:50
//