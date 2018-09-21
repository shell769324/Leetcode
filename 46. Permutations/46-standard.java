/* Recursive thinking: permute([1, 2, 3, 4]) = [1, permute({2, 3, 4})]
 * + [2, permute({1, 3, 4})] + [3, permute({1, 2, 4})] 
 * + [4, permute({1, 2, 3})]
 */
public void swap(int[] nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
  
public List<Integer> arrayToList(int[] nums) {
  List<Integer> res = new ArrayList<>();
  for(int i = 0; i < nums.length; i++) {
    res.add(nums[i]);
  }
  return res;
}
  
public void helper(int[] nums, List<List<Integer>> res, int pointer) {
  if(pointer == nums.length - 1) {
    res.add(arrayToList(nums));
    return;
  }
  for(int i = pointer; i < nums.length; i++) {
    swap(nums, pointer, i);
    helper(nums, res, pointer + 1);
    swap(nums, pointer, i);
  }
}
  
public List<List<Integer>> permute(int[] nums) {
  List<List<Integer>> res = new ArrayList<>();
  if(nums.length == 0) return res;
  helper(nums, res, 0);
  return res;
}