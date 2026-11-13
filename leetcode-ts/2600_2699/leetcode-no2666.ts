// problem:  https://leetcode.cn/problems/allow-one-function-call/?envType=problem-list-v2&envId=FeuPdeiM


type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined

function once(fn: Function): OnceFn {
    let called = false;
    return function (...args) {
        if (!called) {
            called = true;
            return fn(...args);
        }
        return undefined;
    };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */

function main(): void {
    let fn = (a, b, c) => (a + b + c)
    let onceFn = once(fn)
    console.log(onceFn(1, 2, 3)); // 6
    console.log(onceFn(2, 3, 6)); // returns undefined without calling fn
}

main();

//
// Created by jing at 2026-06-12 20:40:35
//
