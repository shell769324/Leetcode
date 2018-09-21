public boolean canJump(int[] nums) {
  int left_most = nums.length - 1;
  for(int i = left_most; i >= 0; i--) {
    if(i + nums[i] >= left_most) left_most = i;
  }
  return left_most == 0;
}