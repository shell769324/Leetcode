void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int pointer) {
  if(pointer == nums.size()) {
    res.push_back(vector<int>(curr));
    return;
  }
  dfs(nums, res, curr, pointer + 1);
  curr.push_back(nums[pointer]);
  dfs(nums, res, curr, pointer + 1);
  curr.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> starter;
  dfs(nums, res, starter, 0);
  return res;
}