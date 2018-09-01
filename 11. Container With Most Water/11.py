"""
When searching for a pair in a 2D list, consider eliminating
multiple pairs at one time
"""
def maxArea(self, heights):
  l = 0
  r = len(heights) - 1
  result = 0;
  while(l < r):
    if(heights[l] < heights[r]):
      result = max(result, (r - l) * heights[l])
      l += 1
    else:
      result = max(result, (r - l) * heights[r])
      r -= 1
  return result