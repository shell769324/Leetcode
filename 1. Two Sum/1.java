/**
 * This problem requires fast operations for
 * 1) Check if an element exists
 * 2) Given an element, knowing its index
 * The best data structure to use is a dictionary
 * Since we cannot use one element twice, check before adding
 */
public int[] twoSum(int[] nums, int target) {
  HashMap<Integer, Integer> dict = new HashMap<Integer, Integer>();
  for(int i = 0; i < nums.length; i++) {
    if(dict.containsKey(target - nums[i])) {
      return new int [] {dict.get(target - nums[i]), i};
    }
    dict.put(nums[i], i);
  }
  return new int[] {0, 0};
}