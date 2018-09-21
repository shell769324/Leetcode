def longestValidParentheses(self, s):
  ret = 0
  # Scan from left to right
  count = {'(':0, ')':0}
  for i in range(len(s)):
    count[s[i]] += 1
    if(count[')'] > count['(']):
      count = {'(':0, ')':0}
    elif(count['('] == count[')']):
      ret = max(ret, count['('] * 2)
  # Scan from right to left   
  count = {'(':0, ')':0}
  for i in range(len(s) - 1, -1, -1):
    count[s[i]] += 1
    if(count['('] > count[')']):
      count = {'(':0, ')':0}
    elif(count['('] == count[')']):
      ret = max(ret, count['('] * 2)
  return ret