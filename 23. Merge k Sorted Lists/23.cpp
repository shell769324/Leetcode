struct NodeCmp {
  public:
  bool operator()(const ListNode* l1, const ListNode* l2) {
    return l1 -> val > l2 -> val;
  }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<ListNode*, vector<ListNode*>, NodeCmp> pq;
  ListNode* dummy = new ListNode(0);
  ListNode* runner = dummy;
  for(ListNode* L: lists) {
    if(L == NULL) continue;
      pq.push(L);
  }
  while(!pq.empty()) {
    ListNode* small = pq.top();
    pq.pop();
    runner -> next = small;
    runner = small;
    if(small -> next) {
      pq.push(small -> next);
    }
  }
  return dummy -> next;
}