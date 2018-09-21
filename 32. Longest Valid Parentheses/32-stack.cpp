int longestValidParentheses(string s) {
  stack<int> st;
  st.push(-1);
  int maxLen = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '(') {
      st.push(i);
    }
    else {
      st.pop(); // discard the '(' since we want the pad
      if(st.empty()) {
        st.push(i); // a pad potentially before a '('
      }
      else {
        maxLen = max(maxLen, i - st.top());
      }
    }
  }
  return maxLen;
}