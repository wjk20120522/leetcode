/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int begin = newInterval.start; int end = newInterval.end;
		unsigned int i;

		// 先把前面的无交集的都压入res中
		for ( i = 0; i < intervals.size(); i++) {
			if (begin > intervals[i].end) {
				res.push_back(intervals[i]);
			}
			else break;
		}
		//整体无交集
		if (i == intervals.size()) {
			Interval s(begin, end);
			res.push_back(s);
			return res;
		}
		else if (end < intervals[i].start) {
			Interval s(begin, end);
			res.push_back(s);
			res.insert(res.end(), intervals.begin()+i, intervals.end());
			return res;
		}

		int tag = i;
		intervals[i].start = intervals[i].start > begin ? begin : intervals[i].start;

		bool get_end = false;
		for (; i < intervals.size(); i++) {
			if (end < intervals[i].start) {
				int max;
				if (i>0) max = end > intervals[i - 1].end ? end : intervals[i - 1].end;
				Interval s(intervals[tag].start, max);  //处于中间
				res.push_back(s);    get_end = true;
				break;
			}
			else if (end <= intervals[i].end) {
				Interval s(intervals[tag].start, intervals[i].end); i++;   //处于i之间
				res.push_back(s);   get_end = true;
				break;
			} 
		}
		if (!get_end && i == intervals.size()) {
			Interval s(intervals[tag].start, end);
			res.push_back(s);
		}
		else if (get_end){
			for (; i < intervals.size(); i++) {
				res.push_back(intervals[i]);
			}
		}
		return res;				

	 }
};