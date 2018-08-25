''' 
The job is to add the leftmost digits up, and add the carry (0 or 1)
put it into a new list node, check if there is carry for the next iteration
Instead of having a "carry" boolean, just declare a global variable sum
divide it by 10 at the end of each iteration.
'''
class Solution(object):
  def addTwoNumbers(self, l1, l2):
    head = runner = ListNode(0)
    sum = 0
    while(l1 or l2 or sum >= 10):
      runner.next = ListNode(0)
      runner = runner.next
      sum /= 10
      if(l1):
        sum += l1.val
        l1 = l1.next
      if(l2):
        sum += l2.val
        l2 = l2.next
      runner.val = sum % 10
    return head.next