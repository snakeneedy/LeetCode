/**
* Your RecentCounter object will be instantiated and called as such:
* var obj = new RecentCounter()
* var param_1 = obj.ping(t)
*/
class RecentCounter {
  requests: number[] = [];
  pos: number = 0;

  ping(t: number): number {
    const rangeMin = t - 3000;
    this.requests.push(t);
    while (this.requests[this.pos] < rangeMin)
      this.pos += 1;
    return this.requests.length - this.pos;
  }
}

function main() {
  let tArr: number[], expectedArr: number[], obj: RecentCounter;

  obj = new RecentCounter();
  tArr = [1, 100, 3001, 3002];
  expectedArr = [1, 2, 3, 3];
  tArr.forEach((t, pos) => {
    const result = obj.ping(t);
    const expected = expectedArr[pos];
    expected === result || console.trace(`expected ${expected}, but ${result}`);
  });
};
main();
