int tri_max(int a, int b, int c) {
  return max(max(a, b), c);
}
  
int findCrossArray(vector<int>& nums, int lo, int hi) {
  int mid = lo + (hi - lo) / 2;
  int max_left = nums[mid];
  int left = 0;
  for(int i = mid; i >= lo; i--) {
    left += nums[i];
    max_left = max(left, max_left);
  }
  int max_right = nums[mid];
  int right = 0;
  for(int i = mid; i < hi; i++) {
    right += nums[i];
    max_right = max(right, max_right);
  }
  return max_left + max_right - nums[mid];
}
  
int helper(vector<int>& nums, int lo, int hi) {
  if(hi - lo == 1) return nums[lo];
  int mid = lo + (hi - lo) / 2;
  return tri_max(helper(nums, lo, mid), helper(nums, mid, hi),
                 findCrossArray(nums, lo, hi));
}
  
int maxSubArray(vector<int>& nums) {
  return helper(nums, 0, nums.size());
}