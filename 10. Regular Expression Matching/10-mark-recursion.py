"""
Use a 2d bool list to prevent recalculation
"""
def isMatch(self, s, p):
  mark = []
  for i in range(len(s) + 1): mark += [[False] * (len(p) + 1)]
    
  def helper(i, j, mark):
    if(i == len(s) and j == len(p)): return True
    if(i > len(s) or j >= len(p)): return False
    if(mark[i][j]): return False
    mark[i][j] = True
    head = i < len(s) and p[j] in {s[i], '.'}
    if(j + 1 < len(p) and p[j + 1] == '*'):
      return helper(i, j + 2, mark) or (head and helper(i + 1, j, mark))
    else:
      return head and helper(i + 1, j + 1, mark)
  
  return helper(0, 0, mark)