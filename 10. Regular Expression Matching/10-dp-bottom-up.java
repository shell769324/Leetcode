public boolean isMatch(String s, String p) {
  int slen = s.length();
  int plen = p.length();
  boolean[][] dp = new boolean[slen + 1][plen + 1];
  dp[slen][plen] = true;
  for(int i = plen - 1; i >= 0; i--) {
    // Not at the last pos and the following char is a star
    // And ...-* or dp[slen][i + 2] is true
    dp[slen][i] = i != plen - 1 && p.charAt(i + 1) == '*' 
              && (i + 2 == plen || dp[slen][i + 2]);
  }
  for(int i = slen - 1; i >= 0; i--) {
    for(int j = plen - 1; j >= 0; j--) {
      boolean head_match = p.charAt(j) == s.charAt(i) || p.charAt(j) == '.';
      if(j != plen - 1 && p.charAt(j + 1) == '*') {
        dp[i][j] = dp[i][j + 2] || (head_match && dp[i + 1][j]);
      }
      else {
        dp[i][j] = head_match && dp[i + 1][j + 1];
      }
    }
  }
  return dp[0][0];
}