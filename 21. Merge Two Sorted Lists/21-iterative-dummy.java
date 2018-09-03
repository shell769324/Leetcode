/* Use dummy and attach the smaller node to the tail
 */
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
  ListNode dummy = new ListNode(0);
  ListNode runner = dummy;
  while(l1 != null && l2 != null) {
    if(l1.val < l2.val) {
      runner.next = l1;
      runner = l1;
      l1 = l1.next;
    }
    else {
      runner.next = l2;
      runner = l2;
      l2 = l2.next;
    }
  }
  runner.next = l1 != null ? l1 : l2;
  return dummy.next;
}