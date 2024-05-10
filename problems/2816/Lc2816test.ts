import { ListNode, array2ListNode, ListNode2array } from './listnode';
import { doubleIt } from './Lc2816';
// import { doubleIt } from './Lc2816_array';

function main() {
  let result: number[], expected: number[], head: ListNode | null;

  head = array2ListNode([1, 8, 9]);
  result = ListNode2array(doubleIt(head));
  expected = [3, 7, 8];
  if (!(expected.length === result.length
    && expected.every((val, idx) => (val === result[idx]))))
    throw new Error(`expected ${expected}, but ${result}`);

  head = array2ListNode([9, 9, 9]);
  result = ListNode2array(doubleIt(head));
  expected = [1, 9, 9, 8];
  if (!(expected.length === result.length
    && expected.every((val, idx) => (val === result[idx]))))
    throw new Error(`expected ${expected}, but ${result}`);
};
main();
