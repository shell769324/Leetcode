/**
 * The job is to add the leftmost digits up, and add the carry (0 or 1)
 * put it into a new list node, check if there is carry for the next iteration
 * Instead of having a "carry" boolean, just declare a global variable sum
 * divide it by 10 at the end of each iteration.
 */
class Solution {
public:
  typedef ListNode list;
  list* addTwoNumbers(list* l1, list* l2) {
    int sum = 0;
    list* dummy = new list(0);
    list* runner = dummy;
    while(sum != 0 || l1 || l2) {
      if(l1) {
        sum += l1 -> val;
        l1 = l1 -> next;
      }
      if(l2) {
        sum += l2 -> val;
        l2 = l2 -> next;
      }
      runner -> next = new list(0);
      runner = runner -> next;
      runner -> val = sum % 10;
      sum /= 10;
    }
    return dummy -> next;
  }
};