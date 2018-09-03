public void dfs(String str, int l, int r, int n, ArrayList<String> ans) {
  if(l == n && r == n) ans.add(str);
  if(l > r) {
    dfs(str + ")", l, r + 1, n, ans);
  }
  if(l < n) {
    dfs(str + "(", l + 1, r, n, ans);
  }
}
  
public List<String> generateParenthesis(int n) {
  if(n == 0) return new ArrayList<String>();
  ArrayList<String> ans = new ArrayList<>();
  dfs("", 0, 0, n, ans);
  return ans;
}