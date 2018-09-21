public void swap(int[] nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
  
public void sortColors(int[] nums) {
  int zero = 0;
  int two = nums.length - 1;
  for(int i = 0; i < nums.length; i++) {
    if(nums[i] == 0 && i >= zero) {
      swap(nums, i, zero++);
    }
    if(nums[i] == 2 && i < two) {
      swap(nums, i--, two--);
    }
  }
}