 class Solution {
 public:
	 vector<vector<int> > combine(int n, int k) {		
		 vector<int> S;
		 for (int i = 1; i <= n; i++) {
			 S.push_back(i);
		 }
		 vector<int>sub;
		 vector< vector<int> > res;
		
		 DFS(S, 0, 0, k,  res, sub);
		 return res;

	 }
	 void DFS(vector<int> &s, int begin, int times, int all, vector< vector<int> > &res, vector<int> &sub) {
		 if (times == all) {
			 res.push_back(sub); return;
		 }

		 for (unsigned int i = begin; i < s.size(); i++) {
			 sub.push_back(s[i]);
			 DFS(s, i + 1, times+1, all, res, sub);
			 sub.pop_back();
			
		 }
	 }
 };