  struct Interval {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

  class Solution {
  public:
	  vector<Interval> merge(vector<Interval> &intervals) {
		  sort(intervals.begin(), intervals.end(), [](Interval& a, Interval&b){return a.start < b.start; });
		  vector<Interval> res;
		  int i = 0, j, len = intervals.size();
		  while (i < len) {
			  j = i;
			  while (++i < len && intervals[i].start <= intervals[j].end) {
				  intervals[j].end = intervals[j].end > intervals[i].end ? intervals[j].end : intervals[i].end;
			  }
			  res.push_back(intervals[j]);
		  }
		  return res;
		  

	  }
  };