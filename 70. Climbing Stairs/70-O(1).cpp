int climbStairs(int n) {
  int a = 1, b = 1;
  while(n--) {
    int temp = b;
    b = a + b;
    a = temp;
  }
  return a;
}