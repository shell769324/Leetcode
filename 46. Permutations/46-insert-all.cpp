/* Recursie thinking: insert uninserted one to all possible slots
 * of all previous solutions
 */
vector<vector<int>> permute(vector<int> &num) {
  vector<vector<int>> ans;
  dfs(num, ans);
  return ans;
}

void dfs(vector<int> &num, vector<vector<int>> &ans) {
  if (num.size() == 1) {
    vector<int> tmp(num.begin(), num.end());
    ans.push_back(tmp);
    return;
  }
    
  vector<vector<int>> ans1;
  vector<int> num1(num.begin() + 1, num.end());
  dfs(num1, ans);
  
  for(int i = 0; i < ans.size(); ++i) {
    for(int j = 0; j <= ans[i].size(); ++j) {
      vector<int> tmp = ans[i];
      tmp.insert(tmp.begin()+j, num[0]);
      ans1.push_back(tmp);
    }
  }
  ans = ans1;
}