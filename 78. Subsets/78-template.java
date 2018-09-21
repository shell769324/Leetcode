public void dfs(int[] nums, int pointer, LinkedList<Integer> curr, 
                List<List<Integer>> res) {
  res.add(new LinkedList<Integer>(curr));
  for(int i = pointer; i < nums.length; i++) {
    curr.add(nums[i]);
      dfs(nums, i + 1, curr, res);
    curr.removeLast();
  }
}
  
public List<List<Integer>> subsets(int[] nums) {
  List<List<Integer>> res = new LinkedList<>();
  dfs(nums, 0, new LinkedList<Integer>(), res);
  return res;
}