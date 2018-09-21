/* Just add up water on top of each bar
 * zero if the bar does not hold any water
 */
public int trap(int[] heights) {
  int len = heights.length;
  int[] lefts = new int[len]; // the height of the highest bar left to the current bar
  int[] rights = new int[len]; // the height of the highest bar right to the current bar
  int left = 0;
  for(int i = 0; i < len; i++) {
    lefts[i] = left;
    left = Math.max(left, heights[i]);
  }
  
  int right = 0;
  for(int i = len - 1; i >= 0; i--) {
    rights[i] = right;
    right = Math.max(right, heights[i]);
  }
  
  int ret = 0;
  for(int i = 0; i < len; i++) {
    int shorter = Math.min(lefts[i], rights[i]);
    ret += shorter > heights[i] ? shorter - heights[i] : 0;
  }
  return ret;
}