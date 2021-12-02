#!/usr/bin/env ts-node
import * as fs from 'fs';
const file = fs.readFileSync("input.txt", "utf8");
const nums = file.split("\n").map(Number);
let current = 0;
let next = 1;
let largerCount = 0;
while (next < nums.length) {
    // use unary operator + to convert to number
    if (nums[current] < nums[next]) {
        largerCount += 1;
    }
    current +=1;
    next += 1;
}
console.log(largerCount);

// need a sliding window of size 3
console.log(nums);
next = 3;
let start = 0;
let windowLargerCount = 0;
while (next < nums.length) {
    // console.log(nums.slice(start+1, next+1));
    const nextWindowSum = nums.slice(start+1, next+1).reduce(add, 0);
    // console.log(nextWindowSum);
    // console.log(nums.slice(start, next));
    const currentWindowSum = nums.slice(start, next).reduce(add, 0);
    // console.log(currentWindowSum)
    if (nextWindowSum > currentWindowSum) {
        windowLargerCount += 1;
        // console.log(windowLargerCount);
    }
    next += 1;
    start += 1;
}
console.log(windowLargerCount);
function add(accumulator: number, a: number) {
    return accumulator + a;
}