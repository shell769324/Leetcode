public int uniquePaths(int m, int n) {
  int[][] dp = new int[m + n][n];
  dp[0][0] = 0;
  for(int i = 1; i < m + n; i++) {
    dp[i][0] = 1;
  }
  for(int i = 1; i < m + n; i++) {
    for(int j = 1; j < Math.min(i + 1, n); j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  return dp[m + n - 1][n - 1];
}