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
console.log(nums.slice(0, 3));