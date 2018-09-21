/** Assembly line
 * Sorting and continue optimizes runtime
 */
vector<vector<int>> combinationSum(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  queue<vector<int>> assemble;
  vector<int> init;
  init.push_back(0); // First element represents sum
  init.push_back(-1); // Second element represents the last viewed element
  assemble.push(init);
  for(int i = 0; i < nums.size(); i++) {
    while(!assemble.empty() && assemble.front()[1] != nums[i]) {
      vector<int> l = assemble.front();
      assemble.pop();
      int currSum = l[0];
      if(currSum + nums[i] > target) continue;
      for(int j = 0; currSum + j * nums[i] <= target; j++) {
        if(currSum + j * nums[i] == target) {
          vector<int> sol(l.begin() + 2, l.end());
          sol.insert(sol.begin(), j, nums[i]);
          res.push_back(sol);
        }
        else {
          vector<int> temp(l);
          temp[0] = currSum + j * nums[i];
          temp[1] = nums[i];
          temp.insert(temp.end(), j, nums[i]);
          assemble.push(temp);
        }
      }
    }
  }
  return res;
}