'''
We need two operations to be fast
1) Check if an element exists in a set
2) Constant update and removal in a set
Note: The type of elements are limited and known
Use an array because char can be cast to int, so char <-> index map
is established within itself
This version is slower than c and cpp version, but it requires 
less thinking and the complexity class is the same
'''
class Solution:
  def lengthOfLongestSubstring(self, s):
    D = [False] * 128
    l, r, maxlen = 0, 0, 0
    while(l < len(s) and r < len(s)):
      if(not D[ord(s[r])]):
        D[ord(s[r])] = True
        r += 1
      else:
        D[ord(s[l])] = False
        l += 1
      if(r - l > maxlen): maxlen = r - l
    return maxlen