/* An advanced example of using dp
 */
public int longestValidParentheses(String s) {
  if(s.length() == 0) return 0;
  int[] dp = new int [s.length()];
  dp[0] = 0;
  int maxLen = 0;
  for(int i = 1; i < s.length(); i++) {
    if(s.charAt(i) == ')') {
      if(s.charAt(i - 1) == '(') {
        dp[i] = i > 1 ? 2 + dp[i - 2] : 2;
      }
      else {
        int open = i - 1 - dp[i - 1];
        if(open >= 0 && s.charAt(open) == '(') {
          dp[i] = dp[i - 1] + 2;
          if(open - 1 >= 0) dp[i] += dp[open - 1];
        }
      }
    }
    maxLen = Math.max(maxLen, dp[i]);
  }
  return maxLen;
}