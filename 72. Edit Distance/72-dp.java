public int minDistance(String word1, String word2) {
  int len1 = word1.length(), len2 = word2.length();
  if(len1 * len2 == 0) {
    return len1 + len2;
  }
  int[][] dp = new int[len1][len2];
  // Fill the base case
  char head1 = word1.charAt(0), head2 = word2.charAt(0);
  boolean found = false;
  for(int i = 0; i < len2; i++) {
    if(head1 == word2.charAt(i)) {
      found = true;
    }
    dp[0][i] = found ? i : i + 1;
  }
  found = false;
  for(int i = 0; i < len1; i++) {
    if(head2 == word1.charAt(i)) {
      found = true;
    }
    dp[i][0] = found ? i : i + 1;
  }
  // Recursive case
  for(int i = 1; i < len1; i++) {
    for(int j = 1; j < len2; j++) {
      if(word1.charAt(i) == word2.charAt(j)) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1]));
      }
    }
  }
  return dp[len1 - 1][len2 - 1];
}