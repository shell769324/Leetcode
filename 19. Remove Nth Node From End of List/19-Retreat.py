"""
Go to the end and run back using an integer
"""
def removeNthFromEnd(self, head, n):
  dummy = ListNode(0)
  dummy.next = head
  def retreat(runner):
    if(runner == None): return 0
    i = retreat(runner.next)
    if(i == n):
      runner.next = runner.next.next
    return i + 1
  retreat(dummy)
  return dummy.next