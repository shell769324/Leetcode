bool canJump(vector<int>& nums) {
  bool dp[nums.size()];
  for(int i = 0; i < nums.size(); i++) dp[i] = false;
  dp[0] = true;
  for(int i = 0; i < nums.size(); i++) {
    if(!dp[i]) return false;
    int end = min(i + nums[i] + 1, (int) nums.size());
    for(int j = i; j < end; j++) {
      dp[j] = true;
    }
  }
  return dp[nums.size() - 1];
}