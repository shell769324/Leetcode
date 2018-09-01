/* A recursive solution, just think about how to make the strings shorter
 * First determine if the heads match since it is used multiple times
 * Then consider p = -*... case (- presents any char), there are
 * two ways to make use of the star, either skip it or use it once and keep it
 * The easier case is letter or .
 */

bool helper(string& s, string& p, int i, int j) {
  if(i == s.length() && j == p.length()) return true;
  if(i > s.length() || j >= p.length()) return false;
  bool head_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
  if(j < p.length() - 1 && p[j + 1] == '*') {
    return helper(s, p, i, j + 2) || (head_match && helper(s, p, i + 1, j));
  }
  return head_match && helper(s, p, i + 1, j + 1);
}

bool isMatch(string s, string p) {
  return helper(s, p, 0, 0);
}