/**
 * We need two operations to be fast
 * 1) Check if an element exists in a set
 * 2) Constant update and removal in a set
 * Note: The type of elements are limited and known
 * Use an array because char can be cast to int, so char <-> index map
 * is established within itself
 */
public int lengthOfLongestSubstring(String s) {
    int [] appear = new int[128];
    for(int i = 0; i < 128; i++) appear[i] = -1;
    int i = 0, j = 0;
    int result = 0;
    while(j < s.length()) {
      if(appear[(int) s.charAt(j)] < i) {
        appear[(int) s.charAt(j)] = j++;
        result = Math.max(j - i, result);
      }
      else {
        i = appear[(int) s.charAt(j)] + 1;
      }
    }  
    return result;
  }