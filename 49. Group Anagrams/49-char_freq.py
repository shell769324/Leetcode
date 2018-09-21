def groupAnagrams(self, strs):
  anagrams = {}
  def getFreq(word):
    res = [0] * 26
    for c in word:
      res[ord(c) - 97] += 1
    return tuple(res)
  for word in strs:
    freq = getFreq(word)
    if(freq in anagrams):
      anagrams[freq].append(word)
    else:
      anagrams[freq] = [word]
    res = []
  while(len(anagrams) != 0):
    key, words = anagrams.popitem()
    res.append(words)
  return res