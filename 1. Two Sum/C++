/*
 * This problem requires fast operations for
 * 1) Check if an element exists
 * 2) Given an element, knowing its index
 * The best data structure to use is a dictionary
 * Since we cannot use one element twice, check before adding
 */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> M;
    for(int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if(M.count(complement) != 0) return vector<int>({M[complement], i});
      M[nums[i]] = i;
    }
    return vector<int>();
  }
};