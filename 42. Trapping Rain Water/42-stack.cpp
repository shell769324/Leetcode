/* The invariant enforces bars closer to the top are shorter
 * The top represents the last bar (potential valley)
 * if the current bar is taller than the last bar, then calculate
 * how much water this bar can hold according the current bar
 * and the second last bar
 */
int trap(vector<int>& height) {
  int ans = 0, curr = 0;
  stack<int> st;
  while(curr < height.size()) {
    if(st.empty() || height[st.top()] >= height[curr]) {
      st.push(curr++);
    }
    else {
      int bar = st.top();
      st.pop();
      if(!st.empty()) {
        ans += (curr - st.top() - 1) * (min(height[curr], height[st.top()]) - height[bar]);
      }
    }
  }
  return ans;
}