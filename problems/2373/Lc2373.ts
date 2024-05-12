import { nestedArraysEqual } from '../common/Common';

function max(...args: number[]): number {
  let result = args[0];
  for (let pos = 1, bound = args.length; pos < bound; pos++) {
    if (result < args[pos]) result = args[pos];
  }
  return result;
};

function largestLocal(grid: number[][]): number[][] {
  const n = grid.length;
  const result: number[][] = [];
  const bound = n - 2;
  for (let rpos = 0; rpos < bound; rpos++) {
    result.push([]);
    for (let cpos = 0; cpos < bound; cpos++) {
      result[rpos].push(max(
        grid[rpos][cpos], grid[rpos][cpos + 1], grid[rpos][cpos + 2],
        grid[rpos + 1][cpos], grid[rpos + 1][cpos + 1], grid[rpos + 1][cpos + 2],
        grid[rpos + 2][cpos], grid[rpos + 2][cpos + 1], grid[rpos + 2][cpos + 2],
      ));
    }
  }
  return result;
};

function main() {
  let result: number[][], expected: number[][], grid: number[][];

  grid = [
    [9, 9, 8, 1],
    [5, 6, 2, 6],
    [8, 2, 6, 4],
    [6, 2, 2, 2]]
  result = largestLocal(grid);
  expected = [
    [9, 9],
    [8, 6]];
  if (!nestedArraysEqual(expected, result)) new Error(`expected ${expected}, but ${result}`);

  grid = [
    [9, 9, 8, 1],
    [5, 6, 2, 6],
    [8, 2, 6, 4],
    [6, 2, 2, 2]];
  result = largestLocal(grid);
  expected = [
    [2, 2, 2],
    [2, 2, 2],
    [2, 2, 2]];
  if (!nestedArraysEqual(expected, result)) new Error(`expected ${expected}, but ${result}`);
};
main();
