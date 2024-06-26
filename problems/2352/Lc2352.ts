function equalPairs(grid: number[][]): number {
  const rowFreq: { [key: string]: number } = {};
  grid.forEach((row) => {
    const rowStr = row.join(',');
    rowFreq[rowStr] = (rowFreq[rowStr] ?? 0) + 1;
  });
  const n = grid.length;
  let result = 0;
  for (let i = 0; i < n; i++) {
    const col: number[] = [];
    for (let j = 0; j < n; j++) col.push(grid[j][i]);
    result += (rowFreq[col.join(',')] ?? 0);
  }
  return result;
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
