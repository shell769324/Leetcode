/* A new way to see binary search is that we can set the lo and hi
 * by some other means. In this problem, if we want to decrease i,
 * we just check if the corresponding nums2[j] is too small.
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    if(len1 > len2) {
      swap(len1, len2);
      swap(nums1, nums2);
    }
    int lo = 0, hi = len1;
    while(lo <= hi) {
      int i = lo + (hi - lo) / 2;
      int j = (len1 + len2 + 1) / 2 - i;
      if(i < hi && nums2[j - 1] > nums1[i]) lo = i + 1;
      else if(i > 0 && nums1[i - 1] > nums2[j]) hi = i - 1;
      else {
        int left = i == 0 ? nums2[j - 1]
                          : j == 0 ? nums1[i - 1]
                                   : max(nums2[j - 1], nums1[i - 1]);
        if((len1 + len2) % 2 == 1) return left;
        int right = i == len1 ? nums2[j]
                           : j == len2 ? nums1[i]
                                       : min(nums2[j], nums1[i]);
        return ((double) (left + right)) / 2.0;
      }
    }
  }