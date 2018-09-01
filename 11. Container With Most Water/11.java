/**
 * When searching for a pair in a 2D list, consider eliminating
 * multiple pairs at one time
 */
public int maxArea(int[] height) {
  int l = 0, r = height.length - 1;
  int result = 0;
  while(l < r) {
    if(height[l] < height[r]) {
      result = Math.max(result, (r - l) * height[l++]);
    }
    else {
      result = Math.max(result, (r - l) * height[r--]);
    }
  }
  return result;
}