function char2num(ch: string) {
  return ch.charCodeAt(0) - 97;
};

function closeStrings(word1: string, word2: string): boolean {
  if (word1.length !== word2.length)
    return false;

  const freq1 = new Array<number>(26).fill(0),
    freq2 = new Array<number>(26).fill(0);
  const present1 = new Set<string>(),
    present2 = new Set<string>();
  for (const w of word1) {
    freq1[char2num(w)]++;
    present1.add(w);
  }
  for (const w of word2) {
    freq2[char2num(w)]++;
    present2.add(w);
  }

  if (present1.size !== present2.size || ![...present1].every((w) => (present2.has(w))))
    return false;

  freq1.sort((l, r) => (l - r));
  freq2.sort((l, r) => (l - r));
  return freq1.every((val, pos) => (val === freq2[pos]));
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

  word1 = 'uau';
  word2 = 'ssx';
  result = closeStrings(word1, word2);
  expected = false;
  expected === result || console.trace(`expected ${expected}, but ${result}`);
};
main();
