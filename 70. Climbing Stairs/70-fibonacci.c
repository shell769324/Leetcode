int climbStairs(int n) {
  if(n <= 1) return 1;
  int* dp = calloc(n + 1, sizeof(int));
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i < n + 1; i++) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  return dp[n];
}