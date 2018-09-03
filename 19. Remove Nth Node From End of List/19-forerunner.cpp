/* Keep the distance at the beginning and run
 * A good strategy for many different link list problem
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = new ListNode(0);
  dummy -> next = head;
  ListNode* forerunner = dummy;
  while(n + 1 > 0) {
    forerunner = forerunner -> next;
    n--;
  }
  ListNode* chaser = dummy;
  while(forerunner != NULL) {
    forerunner = forerunner -> next;
    chaser = chaser -> next;
  }
  chaser -> next = chaser -> next -> next;
  return dummy -> next;
}