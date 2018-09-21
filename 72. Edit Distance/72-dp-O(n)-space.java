public int minDistance(String word1, String word2) {
  int len1 = word1.length(), len2 = word2.length();
  if(len1 * len2 == 0) {
    return len1 + len2;
  }
  int[] prev = new int[len2], curr = new int[len2];
  boolean found = false;
  for(int i = 0; i < len2; i++) {
    if(word1.charAt(0) == word2.charAt(i)) {
      found = true;
    }
    prev[i] = found ? i : i + 1;
  }
  found = word2.charAt(0) == word1.charAt(0);
  for(int i = 1; i < len1; i++) {
    if(word2.charAt(0) == word1.charAt(i)) {
      found = true;
    }
    curr[0] = found ? i : i + 1;
    for(int j = 1; j < len2; j++) {
      if(word1.charAt(i) == word2.charAt(j)) {
        curr[j] = prev[j - 1];
      }
      else {
        curr[j] = 1 + Math.min(curr[j - 1], Math.min(prev[j], prev[j - 1]));
      }
    }
    int[] temp = prev;
    prev = curr;
    curr = temp;
  }
  return prev[len2 - 1];
}