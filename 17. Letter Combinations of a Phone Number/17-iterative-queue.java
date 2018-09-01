/* Use a fifo structure
 * Like a assembly line
 * Recursive thinking
 */
public List<String> letterCombinations(String digits) {
  if(digits.length() == 0) return new LinkedList<String>();
  String [] intToLets = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  LinkedList<String> ret = new LinkedList<>();
  ret.add("");
  for(int i = 0; i < digits.length(); i++) {
    char currChar = digits.charAt(i);
    char[] lets = intToLets[Character.getNumericValue(currChar)].toCharArray();
    while(ret.peek().length() == i) {
      String str = ret.remove();
      for(char c : lets) {
        ret.add(str + c);
      }
    }
  }
  return ret;
}