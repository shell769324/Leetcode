/** An extremely important example of generating things 
 * relying on calatan number. Similar problems including
 * generating full-leaf binary trees of n nodes
 */
public List<String> generateParenthesis(int n) {
  ArrayList<List<String>> banks = new ArrayList<List<String>>();
  banks.add(Collections.singletonList(""));
  for(int i = 1; i <= n; i++) {
    ArrayList<String> curr = new ArrayList<>();
    for(int l = 0; l < i; l++) {
      for(String sl: banks.get(l)) {
        for(String sr: banks.get(i - 1 - l)) {
          curr.add("(" + sl + ")" + sr);
        }
      }
    }
    banks.add(curr);
  }
  return banks.get(n);
}