public List<List<String>> groupAnagrams(String[] strs) {
  String[] store = new String[strs.length];
  for(int i = 0; i < strs.length; i++) {
    store[i] = new String(strs[i]);
  }
  for(int i = 0; i < strs.length; i++) {
    char[] word = strs[i].toCharArray();
    Arrays.sort(word);
    strs[i] = new String(word);
  }
  HashMap<String, Integer> getIndex = new HashMap<>();
  List<List<String>> res = new ArrayList<>();
  for(int i = 0; i < strs.length; i++) {
    if(getIndex.containsKey(strs[i])) {
      int index = getIndex.get(strs[i]);
      res.get(index).add(store[i]);
    }
    else {
      List<String> temp = new ArrayList<>();
      temp.add(store[i]);
      getIndex.put(strs[i], res.size());
      res.add(temp);
    }
  }
  return res;
}