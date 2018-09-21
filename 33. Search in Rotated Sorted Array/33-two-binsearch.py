"""
First search for the breakpoint
Then do shifted binary search
"""
def search(self, nums, target):
  if(len(nums) == 0): return -1
  lo = 0
  hi = len(nums) - 1
  pivot = 0
  while(nums[lo] > nums[hi]):
    mid = lo + (hi - lo) // 2
    if(nums[mid] > nums[mid + 1]):
      pivot = mid + 1
      break
    elif(nums[mid] < nums[0]):
      hi = mid
    else:
      lo = mid + 1
  lo = 0
  hi = len(nums)
  while(lo < hi):
    mid = lo + (hi - lo) // 2
    shifted = (mid + pivot) % len(nums)
    if(nums[shifted] == target): return shifted
    elif(nums[shifted] < target): lo = mid + 1
    else: hi = mid
  return -1