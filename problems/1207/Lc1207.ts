function uniqueOccurrences(arr: number[]): boolean {
  const numCount = new Map<number, number>();
  arr.forEach((n) => {
    numCount.set(n, (numCount.get(n) ?? 0) + 1);
  });
  const numCountSet = new Set<number>(numCount.values());
  return numCountSet.size === numCount.size;
};

function main() {
  let arr: number[], result: boolean, expected: boolean;

  arr = [1, 2, 2, 1, 1, 3];
  result = uniqueOccurrences(arr);
  expected = true;
  console.assert(expected === result, `expected ${expected}, but ${result}`);

  arr = [1, 2];
  result = uniqueOccurrences(arr);
  expected = false;
  console.assert(expected === result, `expected ${expected}, but ${result}`);

  arr = [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0];
  result = uniqueOccurrences(arr);
  expected = true;
  console.assert(expected === result, `expected ${expected}, but ${result}`);
};
main();
