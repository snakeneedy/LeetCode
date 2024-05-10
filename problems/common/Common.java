public class Common {
  static public void printArray(int[] values) {
    System.out.print('{');
    if (values.length > 0) {
      System.out.print(values[0]);
      for (int pos = 1; pos < values.length; ++pos) {
        System.out.print(',');
        System.out.print(values[pos]);
      }
    }
    System.out.print('}');
  }

  static public boolean equalArrays(int[] lValues, int[] rValues) {
    if (lValues == null || rValues == null || lValues.length != rValues.length)
      return false;
    for (int pos = 0; pos < lValues.length; ++pos) {
      if (lValues[pos] != rValues[pos])
        return false;
    }
    return true;
  }
}
