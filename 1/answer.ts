#!/usr/bin/env ts-node
import * as fs from 'fs';
const file = fs.readFileSync("input.txt", "utf8");
console.log(file)