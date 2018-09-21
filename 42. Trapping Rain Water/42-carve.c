/* The idea is to scan from left to right find the next bar taller
 * than or equally tall as the current bar. Carve out the area between them.
 * Sum up to the answer
 */

int max(int m, int n) {
  return m > n ? m : n;
}

int min(int m, int n) {
  return m < n ? m : n;
}

int trap(int* heights, int heightSize) {
  if(heightSize <= 2) return 0;
  int maxIdx = 0;
  for(int i = 0; i < heightSize; i++) {
    if(heights[i] > heights[maxIdx]) maxIdx = i;
  }
  int left = 0;
  int* next = calloc(heightSize, sizeof(int));
  for(int i = 0; i <= maxIdx; i++) {
    if(heights[i] >= heights[left]) {
      next[left] = i;
      left = i;
    }
    next[i] = i;
  }
  int right = heightSize - 1;
  for(int i = heightSize - 1; i >= maxIdx; i--) {
    next[i] = i;
    if(heights[i] >= heights[right]) {
      next[i] = right;
      right = i;
    }
  }
  int water = 0;
  for(int i = 0; i < heightSize; i++) {
    water += max(0, (next[i] - i - 1)) * min(heights[i], heights[next[i]]);
    for(int j = i + 1; j < next[i]; j++) {
      water -= heights[j];
    }
  }
  return water;
}