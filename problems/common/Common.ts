function arraysEqual(arr1: any[], arr2: any[]) {
  return (arr1.length === arr2.length
    && arr1.every((val, pos) => (val === arr2[pos])));
};

function nestedArraysEqual(arr1: any[], arr2: any[]): boolean {
  return (arr1.length === arr2.length
    && arr1.every((val, pos) => (
      (Array.isArray(val) && Array.isArray(arr2[pos]) && nestedArraysEqual(val, arr2[pos]))
      || val === arr2[pos])));
};
