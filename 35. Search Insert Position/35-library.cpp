// A shameful solution using algorithm library
int searchInsert(vector<int>& nums, int target) {
   return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}