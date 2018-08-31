/**
 * The job is to add the leftmost digits up, and add the carry (0 or 1)
 * put it into a new list node, check if there is carry for the next iteration
 * Instead of having a "carry" boolean, just declare a global variable sum
 * divide it by 10 at the end of each iteration.
 */
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
  ListNode dummy = new ListNode(0);
  ListNode runner = dummy;
  int sum = 0;
  while(sum >= 10 || l1 != null || l2 != null) {
    sum /= 10;
    if(l1 != null) {
      sum += l1.val;
      l1 = l1.next;
    }
    if(l2 != null) {
      sum += l2.val;
      l2 = l2.next;
    }
    runner.next = new ListNode(0);
    runner = runner.next;
    runner.val = sum % 10;
  }
  return dummy.next;
}