public void dfs(int[] nums, LinkedList<Integer> curr, int need,
                int pointer, List<List<Integer>> ret) {
  if(need == 0) {
    ret.add(new LinkedList(curr));
  }
  if(need <= 0) return;
  for(int i = pointer; i < nums.length; i++) {
    curr.add(nums[i]);
    dfs(nums, curr, need - nums[i], i, ret);
    curr.removeLast();
  }
}
public List<List<Integer>> combinationSum(int[] nums, int target) {
  List<List<Integer>> ret = new LinkedList<>();
  dfs(nums, new LinkedList<Integer>(), target, 0, ret);
  return ret;
}