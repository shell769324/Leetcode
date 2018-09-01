"""
Instead of using a queue, just create a temp holder to store the strings
of current length
"""
def letterCombinations(self, digits):
    if(len(digits) == 0): return []
    res = [""]
    intToChars = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    for i in range(len(digits)):
      hold = []
      for j in range(len(res)):
        chars = intToChars[int(digits[i])]
        for k in range(len(chars)):
          hold.append(res[j] + chars[k])
      res = hold
    return res