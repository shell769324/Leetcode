vector<vector<int>> subsets(vector<int>& nums) {
  int len = pow(2, nums.size());
  vector<vector<int>> res(len, vector<int>());
  for(int i = 0; i < nums.size(); i++) {
    for(int j = 0; j < len; j++) {
      if(j >> i & 1) {
        res[j].push_back(nums[i]);
      }
    }
  }
  return res;
}