/* Check c++ first
 * The job is to add the leftmost digits up, and add the carry (0 or 1)
 * put it into a new list node, check if there is carry for the next iteration
 * Instead of having a "carry" boolean, just declare a global variable sum
 * divide it by 10 at the end of each iteration.
 * This solution does not use a dummy note, so an extra check before
 * allocating new memory
 */
typedef struct ListNode list;

list* addTwoNumbers(list* l1, list* l2) {
  list* res = calloc(1, sizeof(list));
  list* head = res;
  int sum = 0;
  while(sum >= 10 || l1 != NULL || l2 != NULL) {
    sum /= 10;
    if(l1 != NULL) {
      sum += l1 -> val;
      l1 = l1 -> next;
    }
    if(l2 != NULL) {
      sum += l2 -> val;
      l2 = l2 -> next;
    }
    res -> val = sum % 10;
    if(l1 != NULL || l2 != NULL || sum >= 10) res -> next = calloc(1, sizeof(list));
    res = res -> next;
  }
  return head;
}