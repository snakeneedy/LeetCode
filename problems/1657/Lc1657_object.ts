function arraysEqual(arr1: any[], arr2: any[]) {
  return (arr1.length === arr2.length
    && arr1.every((val, pos) => (val === arr2[pos])));
};

function closeStrings(word1: string, word2: string): boolean {
  if (word1.length !== word2.length) return false;

  const word1count: { [key: string]: number } = {},
    word2count: { [key: string]: number } = {};
  for (const w of word1)
    word1count[w] = (word1count[w] ?? 0) + 1;
  for (const w of word2)
    word2count[w] = (word2count[w] ?? 0) + 1;
  return (arraysEqual(Object.keys(word1count).sort(), Object.keys(word2count).sort())
    && arraysEqual(Object.values(word1count).sort(), Object.values(word2count).sort()));
};

function main() {
  let word1: string, word2: string, result: boolean, expected: boolean;

  word1 = 'abc';
  word2 = 'bca';
  result = closeStrings(word1, word2);
  expected = true;
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  word1 = 'a';
  word2 = 'aa';
  result = closeStrings(word1, word2);
  expected = false;
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  word1 = 'cabbba';
  word2 = 'abbccc';
  result = closeStrings(word1, word2);
  expected = true;
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  word1 = 'abbzccca';
  word2 = 'babzzczc';
  result = closeStrings(word1, word2);
  expected = true;
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  word1 = 'aaabbbbccddeeeeefffff';
  word2 = 'aaaaabbcccdddeeeeffff';
  result = closeStrings(word1, word2);
  expected = false;
  expected === result || console.trace(`expected ${expected}, but ${result}`);
};
main();
