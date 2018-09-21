from collections import deque

class Solution:
  def subsets(self, nums):
    dq = deque()
    dq.append([])
    for i in range(len(nums)):
      for j in range(2 ** i):
        prev = dq.popleft()
        dq.append(prev)
        dq.append(prev + [nums[i]])
    res = []
    while(len(dq) != 0):
      res.append(dq.popleft())
    return res