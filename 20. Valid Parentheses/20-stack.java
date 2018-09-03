
public boolean isValid(String s) {
  Stack<Character> toClose = new Stack<>();
  toClose.push('-'); // in case toClose is empty
  for(int i = 0; i < s.length(); i++) {
    char c = s.charAt(i);
    if(c == ')' && toClose.pop() != '(') return false;
    else if(c == ']' && toClose.pop() != '[') return false;
    else if(c == '}' && toClose.pop() != '{') return false;
    else if(c == '(' || c == '[' || c =='{') toClose.push(c);
  }
  return toClose.pop() == '-';
}
