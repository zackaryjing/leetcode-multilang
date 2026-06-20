// problem:  https://leetcode.cn/problems/function-composition/?envType=problem-list-v2&envId=FeuPdeiM

type F = (x: number) => number;

function compose(functions: F[]): F {
	return function(x) {
        for (var f of functions.reverse()) {
            x = f(x);
        }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */

function main(): void {
    const fn = compose([x => x + 1, x => 2 * x]);
    console.log(fn(4));
}

main();

//
// Created by jing at 2026-06-12 20:40:35
//