// problem:https://leetcode.cn/problems/counter/?envType=problem-list-v2&envId=FeuPdeiM

function createCounter(n: number): () => number {
    return function() {
        return n++;
    }
}


/**
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

function main(): void {
    const counter = createCounter(10);
    console.log(counter())
    console.log(counter())
    console.log(counter())
}

main();

//
// Created by jing at 2026-05-31 17:26:07
//