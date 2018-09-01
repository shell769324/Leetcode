/* A new way to see binary search is that we can set the lo and hi
 * by some other means. In this problem, if we want to decrease i,
 * we just check if the corresponding nums2[j] is too small.
 */
int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  if(nums1Size > nums2Size) {
    int tempSize = nums1Size;
    nums1Size = nums2Size;
    nums2Size = tempSize;
    int* temp = nums1;
    nums1 = nums2;
    nums2 = temp;
  }
  int lo = 0, hi = nums1Size;
  int total = (nums1Size + nums2Size + 1) / 2;
  while(lo <= hi) {
    int i = lo + (hi - lo) / 2;
    int j = total - i;
    if(i > 0 && nums1[i - 1] > nums2[j]) hi = i - 1;
    else if(i < hi && nums2[j - 1] > nums1[i]) lo = i + 1;
    else {
      int left = i == 0 ? nums2[j - 1]
                        : j == 0 ? nums1[i - 1]
                                 : max(nums1[i - 1], nums2[j - 1]);
      if((nums1Size + nums2Size) % 2 == 1) return left;
      int right = i == nums1Size ? nums2[j]
                                 : j == nums2Size ? nums1[i]
                                                  : min(nums1[i], nums2[j]);
      return ((double) (left + right)) / 2.0;
    }
  }
  return -1;
}