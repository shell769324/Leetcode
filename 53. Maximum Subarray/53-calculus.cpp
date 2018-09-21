int maxSubArray(vector<int>& nums) {
  int local = 0;
  int sum = 0;
  for(int i = 0; i < nums.size(); i++) {
    local += nums[i];
    if(local < 0) {
      local = 0;
    }
    sum = max(local, sum);
  }
  return sum == 0 ? *max_element(nums.begin(), nums.end()): sum;
}