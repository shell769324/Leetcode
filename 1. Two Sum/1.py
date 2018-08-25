# Python also has a builtin dict, so copy the thoughts from CPP solution
class Solution:
  def twoSum(self, nums, target):
    dict = {}
    for i in range(len(nums)):
      if(nums[i] in dict):
        return [dict[nums[i]], i]
      dict[target - nums[i]] = i