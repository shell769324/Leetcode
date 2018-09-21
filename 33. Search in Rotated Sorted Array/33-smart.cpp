/** An innovative way to use binary search
 *
 */
int search(vector<int>& nums, int target) {
  if(nums.size() == 0) return -1;
  bool left = target >= nums[0];
  int modify = left ? INT_MAX : INT_MIN;
  int lo = 0, hi = nums.size();
  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int num = (nums[mid] >= nums[0] == left) ? nums[mid] : modify;
    if(num == target) return mid;
    else if(num > target) hi = mid;
    else lo = mid + 1;
  }
  return -1;
}