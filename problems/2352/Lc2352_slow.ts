function sum(nums: number[]): number {
  return nums.reduce((acc, cur) => (acc += cur), 0);
};

function equalPairs(grid: number[][]): number {
  const n = grid.length;
  const rowFreq: { [key: string]: number } = {},
    colFreq: { [key: string]: number } = {};
  for (let i = 0; i < n; i++) {
    const row: number[] = [],
      col: number[] = [];
    for (let j = 0; j < n; j++) {
      row.push(grid[i][j]);
      col.push(grid[j][i]);
    }
    const rowStr = row.join(','),
      colStr = col.join(',');
    rowFreq[rowStr] = (rowFreq[rowStr] ?? 0) + 1;
    colFreq[colStr] = (colFreq[colStr] ?? 0) + 1;
  }
  return sum(
    Object
      .keys(rowFreq)
      .map(key => rowFreq[key] * (colFreq[key] ?? 0))
  );
};

function main() {
  let grid: number[][], result: number, expected: number;

  grid = [[3, 2, 1], [1, 7, 6], [2, 7, 7]];
  result = equalPairs(grid);
  expected = 1;
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  grid = [[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]];
  result = equalPairs(grid);
  expected = 3;
  expected === result || console.trace(`expected ${expected}, but ${result}`);
};
main();
