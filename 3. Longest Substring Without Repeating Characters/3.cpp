/**
 * We need two operations to be fast
 * 1) Check if an element exists in a set
 * 2) Constant update and removal in a set
 * Note: The type of elements are limited and known
 * Use an array because char can be cast to int, so char <-> index map
 * is established within itself
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, res = 0;
    int M[128];
    for(int i = 0; i < 128; i++) M[i] = -1;
    while(j < s.length()) {
      if(M[s[j]] < i) {
        M[s[j]] = j++;
        res = max(j - i, res);
      }
      else i = M[s[j]] + 1;
    }
    return res;
  }
};