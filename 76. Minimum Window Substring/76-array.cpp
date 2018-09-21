string minWindow(string s, string t) {
  // If reach == t.length(), t is covered
  int reach = 0;
  int slen = s.length(), tlen = t.length();
  // All chars we need to cover
  vector<int> target(128, 0);
  for(int i = 0; i < tlen; i++) target[(int) t[i]]++;
    
  vector<int> count(128, 0);
  int left = 0;
  int pos = 0, len = INT_MAX;
  for(int i = 0; i < slen; i++) {
    // Only increment reach when the s[i] covers t and not overkills
    if(count[(int) s[i]] < target[(int) s[i]]) reach++;
    // Keep track of what chars are in the window
    count[(int) s[i]]++;
    // Discard leftmost char if there are already enough of them
    while(count[(int) s[left]] > target[(int) s[left]]) {
      count[(int) s[left]]--;
      left++;
    }
    if(reach == tlen && i - left + 1 < len){
      len = i - left + 1;
      pos = left;
    }
  }
  return reach == tlen ? s.substr(pos, len) : "";
}