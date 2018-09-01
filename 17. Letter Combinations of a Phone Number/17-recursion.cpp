/** Two strategies for finding permutations:
 * 1) Use a holder
 * 2) Use DFS with a for loop
 */
void DFS(string& digits, int at, string& curr,
                   map<char, string>& numToLets, vector<string>& ret) {
  if(at == digits.length()) {
    ret.push_back(curr.substr(0, curr.length()));
  }
  string lets = numToLets[digits[at]];
  for(int i = 0; i < lets.length(); i++) {
    curr[at] = lets[i];
    DFS(digits, at + 1, curr, numToLets, ret);
  }
}

vector<string> letterCombinations(string digits) {
  if(digits.length() == 0) {
    return vector<string>();
  }
  map<char, string> numToLets;
  string A[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  for(int i = 0; i < 8; i++) {
    numToLets[(char) (i + 50)] = A[i];
  }
  vector<string> ret;
  string hold(digits);
  DFS(digits, 0, hold, numToLets, ret);
  return ret;
}