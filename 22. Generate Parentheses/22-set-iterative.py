"""
Set is another model useful for assembly line
When there are multiple ways to make an incomplete product,
use set to avoid duplicates
"""
def generateParenthesis(self, n):
  incomplete = {}
  incomplete["("] = (1, 0)
  ans = []
  while(len(incomplete) > 0):
    parens, (op, cl) = incomplete.popitem()
    if(op == n):
      if(cl == n):
        ans.append(parens)
      else:
        incomplete[parens + ")"] = (op, cl + 1)
    elif(op == cl):
      incomplete[parens + "("] = (op + 1, cl)
    else:
      incomplete[parens + "("] = (op + 1, cl)
      incomplete[parens + ")"] = (op, cl + 1)
  return ans