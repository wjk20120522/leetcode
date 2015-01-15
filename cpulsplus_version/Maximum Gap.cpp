class Solution {
public:
    
    int maximumGap(vector<int> &num) {
          if (num.size() < 2) return 0;
		  int max = num[0];
		  int min = num[0];
		  for (auto n : num) {
			  max = max > n ? max : n;
			  min = min < n ? min : n;
		  }
		  int gap = (max - min) / num.size() +1;   // gap must at least one
		  int buck_size = (max - min) / gap + 1;    
		  vector< vector<int> > buckets(buck_size);

		  for (int i = 0; i < num.size(); i++) {
			  int idx = (num[i] - min) / gap;
			  if (buckets[idx].empty()) {
				  buckets[idx].push_back(num[i]);
				  buckets[idx].push_back(num[i]);
			  }
			  else {
				  buckets[idx][0] = buckets[idx][0] < num[i] ? buckets[idx][0] : num[i];
				  buckets[idx][1] = buckets[idx][1] > num[i] ? buckets[idx][1] : num[i];
			  }
		  }
		  int maxGap = 0;
		  int prev = 0;
		  for (int i = 0; i < buck_size; i++) {
			  if (buckets[i].empty()) continue;
			  int gap = buckets[i][0] - buckets[prev][1];
			  maxGap = maxGap > gap ? maxGap : gap;
			  prev = i;
		  }
		  return maxGap;
    }
};