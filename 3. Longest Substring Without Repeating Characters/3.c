/**
 * We need two operations to be fast
 * 1) Check if an element exists in a set
 * 2) Constant update and removal in a set
 * Note: The type of elements are limited and known
 * Use an array because char can be cast to int, so char <-> index map
 * is established within itself
 */
int lengthOfLongestSubstring(char* s) {
  int* dict = calloc(128, sizeof(int));
  for(int i = 0; i < 128; i++) dict[i] = -1;
  int len = strlen(s);
  int l = 0, max = 0;
  for(int i = 0; i < len; i++) {
    if(dict[s[i]] >= l) {
      l = dict[s[i]] + 1;
    }
    dict[s[i]] = i;
    max = (i - l + 1) > max ? i - l + 1: max;
  }
  free(dict);
  return max;
}