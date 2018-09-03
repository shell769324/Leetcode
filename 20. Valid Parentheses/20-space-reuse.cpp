bool isMatch(char c1, char c2){
  if(c1 == '(' && c2 == ')') return true;
  if(c1 == '[' && c2 == ']') return true;
  if(c1 == '{' && c2 == '}') return true;
  return false;
}

/* Use s[0:i] as a stack
 */
bool isValid(string s) {
  int top = -1; // Mimic a stack
  for(int i = 0; i < s.length(); i++) {
    if(top < 0 || !isMatch(s[top] , s[i])) {
      top++;
      s[top] = s[i];
    }
    else {
      top--;
    }
  }
  return top == -1;
}