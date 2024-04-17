function findDifference(nums1: number[], nums2: number[]): number[][] {
  const set1 = new Set(nums1);
  const set2 = new Set(nums2);
  const result: number[][] = [[], []];
  for (const x of set1) {
    if (!set2.has(x)) result[0].push(x);
  }
  for (const x of set2) {
    if (!set1.has(x)) result[1].push(x);
  }
  return result;
};

function arrayEqual(arr1: any[], arr2: any[]): boolean {
  if (arr1.length !== arr2.length) return false;
  return arr1.every((val, i) => {
    if (Array.isArray(val) && Array.isArray(arr2[i]))
      return arrayEqual(val, arr2[i]);
    return val === arr2[i];
  });
}
function main() {
  let nums1: number[], nums2: number[], expected: number[][], result: number[][];

  nums1 = [1, 2, 3];
  nums2 = [2, 4, 6];
  expected = [[1, 3], [4, 6]];
  result = findDifference(nums1, nums2);
  console.assert(arrayEqual(expected, result), 'expected', expected, ', but', result);

  nums1 = [1, 2, 3, 3];
  nums2 = [1, 1, 2, 2];
  expected = [[3], []];
  result = findDifference(nums1, nums2);
  console.assert(arrayEqual(expected, result), 'expected', expected, ', but', result);
};
main();
