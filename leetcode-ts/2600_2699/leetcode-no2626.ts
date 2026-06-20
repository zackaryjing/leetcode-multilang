// problem:  https://leetcode.cn/problems/array-reduce-transformation/?envType=problem-list-v2&envId=FeuPdeiM

type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    for (var num of nums) {
        init = fn(init,num);
    }
    return init;
};

function main(): void {
    console.log(reduce([1,2,3,4],  function sum(accum, curr) { return accum + curr; },10));
}

main();

//
// Created by jing at 2026-06-12 20:49:39
//