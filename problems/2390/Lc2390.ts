function removeStars(s: string): string {
  const arr: string[] = [];
  for (const ch of s) {
    if (ch === '*') {
      arr.pop();
    } else {
      arr.push(ch);
    }
  }
  return arr.join('');
};

function main() {
  let s: string, result: string, expected: string;

  s = 'leet**cod*e'
  result = removeStars(s)
  expected = 'lecoe'
  expected === result || console.trace(`expected ${expected}, but ${result}`);

  s = 'erase*****'
  result = removeStars(s)
  expected = ''
  expected === result || console.trace(`expected ${expected}, but ${result}`);
};
main();
