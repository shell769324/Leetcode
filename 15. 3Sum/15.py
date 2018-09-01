"""
Only use the first of a series of identical numbers
1) Make sure -2 -2 4 can be found
2) Make sure no identical triplet
Same logic for the inner while loop
"""
def threeSum(self, nums):
  nums.sort()
  ret = []
  for i in range(len(nums) - 1):
    if(nums[i] > 0): return ret
    if(i != 0 and nums[i] == nums[i - 1]): continue
    lo, hi = i + 1, len(nums) - 1
    while(lo < hi):
      curr = nums[i] + nums[lo] + nums[hi]
      if(curr == 0):
        ret.append([nums[i], nums[lo], nums[hi]])
        while(lo < hi and nums[lo] == nums[lo + 1]): lo += 1
        while(lo < hi and nums[hi] == nums[hi - 1]): hi -= 1
        lo += 1
        hi -= 1
      elif(curr < 0):
        lo += 1
      else:
        hi -= 1
  return ret