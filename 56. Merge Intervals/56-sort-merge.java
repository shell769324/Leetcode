class IntervalCompare implements Comparator<Interval> {
  public int compare(Interval a, Interval b) {
    return a.start - b.start;
  }
}

class Solution {
  public List<Interval> merge(List<Interval> intervals) {
    Collections.sort(intervals, new IntervalCompare());
    List<Interval> res = new ArrayList<>();
    int lastEnd = -1;
    for(int i = 0; i < intervals.size(); i++) {
      Interval curr = intervals.get(i);
      if(curr.end > lastEnd) {
        if(curr.start > lastEnd) {
          res.add(curr);
        }
        else if(!res.isEmpty()) {
          res.get(res.size() - 1).end = curr.end;
        }
        lastEnd = curr.end;
      }
    }
    return res;
  }
}