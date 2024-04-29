function arrayEqual(arr1: any[], arr2: any[]): boolean {
  if (arr1.length !== arr2.length) return false;
  return arr1.every((val, i) => {
    if (Array.isArray(val) && Array.isArray(arr2[i]))
      return arrayEqual(val, arr2[i]);
    return val === arr2[i];
  });
}
