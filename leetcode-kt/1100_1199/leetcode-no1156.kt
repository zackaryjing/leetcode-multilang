// problem: https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/

package leetcodeNo1156

import kotlin.math.max

class Solution {
    fun maxRepOpt1(text: String): Int {
        val seg = Array<MutableList<Pair<Int, Int>>>(26) { mutableListOf() };
        var curChar = text[0]
        var prePos = 0
        for ((i, c) in text.withIndex()) {
            if (c != curChar) {
                seg[curChar - 'a'].add(Pair(prePos, i - 1))
                curChar = c
                prePos = i
            }
        }
        seg[curChar - 'a'].add(Pair(prePos, text.length - 1))

//        println(seg.mapIndexed { i, list ->
//            "'${'a' + i}': ${list.joinToString(", ") { "(${it.first}, ${it.second})" }}"
//        }.joinToString("\n"))


        var res = 0
        for (list in seg) {
            val n = list.size
            if (n == 0) {
                continue
            } else if (n == 1) {
                res = max(res, list[0].second - list[0].first + 1)
            } else if (n == 2) {
                res = max(
                    res, max(
                        list[0].second - list[0].first + 2,
                        +list[1].second - list[1].first + 2
                    )
                )
                if (list[1].first == list[0].second + 2) {
                    res = max(
                        res, list[0].second - list[0].first + 1
                                + list[1].second - list[1].first + 1
                    )
                }

            } else {
                res = max(res, list[0].second - list[0].first + 2)
                for (i in 1..<n) {
                    res = max(res, list[i].second - list[i].first + 2)

                    if (list[i].first == list[i - 1].second + 2) {
                        res = max(
                            res, list[i - 1].second - list[i - 1].first + 1
                                    + list[i].second - list[i].first + 1 + 1
                        )
                    }
                }
            }
        }
        return res
    }
}

fun main() {
    val test = Solution()
    println(test.maxRepOpt1("abcdef"));
    println(test.maxRepOpt1("aaabbaaa"));
    println(test.maxRepOpt1("ababa"));
    println(test.maxRepOpt1("aaabaaa"));
    println(test.maxRepOpt1("aaaaa"));
}

//
// Created By Zackary At 2025/5/12 23:44
//