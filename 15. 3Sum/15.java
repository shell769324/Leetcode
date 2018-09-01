/* Only use the first of a series of identical numbers
 * 1) Make sure -2 -2 4 can be found
 * 2) Make sure no identical triplet
 * Same logic for the inner while loop
 */
public List<List<Integer>> threeSum(int[] nums) {
    Arrays.sort(nums);
    ArrayList<List<Integer>> ret = new ArrayList<>();
    for(int i = 0; i < nums.length - 2; i++) {
      if(nums[i] > 0) break;
      if(i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1, r = nums.length - 1;
      while(l < r) {
        int curr = nums[i] + nums[l] + nums[r];
        if(curr == 0) {
          ret.add(Arrays.asList(nums[i], nums[l], nums[r]));
          while(l < r && nums[l] == nums[l + 1]) l++;
          while(l < r && nums[r] == nums[r - 1]) r--;
          l++;
          r--;
        }
        else if(curr < 0) {
          l++;
        }
        else {
          r--;
        }
      }
    }
    return ret;
  }