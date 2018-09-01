/* Using the idea of recursion, when filling dp[i][j], examine s[i - 1]
 * and p[j - 1]. Remember only consider the current chars and previous
 * cases. Don't need to check if the next char is a star
 */
bool isMatch(char* s, char* p) {
  int slen = strlen(s);
  int plen = strlen(p);
  // Memory allocation
  bool** dp = calloc(slen + 1, sizeof(bool*));
  for(int i = 0; i <= slen; i++) dp[i] = calloc(plen + 1, sizeof(bool));
  // Base case
  dp[0][0] = true;
  for(int i = 1; i <= plen; i++) dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
  // Inductive case
  for(int i = 1; i <= slen; i++) {
    for(int j = 1; j <= plen; j++) {
      if(p[j - 1] == '*') {
        dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
      }
      else {
        dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
      }
    }
  }
  return dp[slen][plen];
}