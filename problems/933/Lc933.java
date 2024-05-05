import java.util.ArrayList;
import java.util.List;

public class Lc933 {
  static Lc933 leetcode = new Lc933();

  /**
   * Your RecentCounter object will be instantiated and called as such:
   * RecentCounter obj = new RecentCounter();
   * int param_1 = obj.ping(t);
   */
  class RecentCounter {
    private List<Integer> requests;
    private int pos, len;

    public RecentCounter() {
      this.requests = new ArrayList<>();
      this.pos = this.len = 0;
    }

    public int ping(int t) {
      int rangeMin = t - 3000;
      this.requests.add(t);
      ++(this.len);
      while (this.requests.get(this.pos) < rangeMin)
        ++(this.pos);
      return this.len - this.pos;
    }
  }

  static void testcase01() {
    RecentCounter obj = leetcode.new RecentCounter();
    int[] tArr = {1, 100, 3001, 3002};
    int[] expectedArr = {1, 2, 3, 3};
    for (int pos = 0; pos < tArr.length; ++pos){
      int t = tArr[pos];
      int result = obj.ping(t);
      int expected = expectedArr[pos];
      assert expected == result : "expected" + String.valueOf(expected) + ", but " + String.valueOf(result);
    }
  }

  public static void main(String[] args) {
    testcase01();
  }
}
