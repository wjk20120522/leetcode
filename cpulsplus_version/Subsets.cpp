class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		 sort(S.begin(), S.end());
		 vector<int>sub;
		 vector< vector<int> > res;

		 DFS(S, 0, res, sub);
		 return res; 

	 }
	 void DFS(vector<int> &s, int begin, vector< vector<int> > &res, vector<int> &sub) {
		 res.push_back(sub);
		 
		 for (unsigned int i = begin; i < s.size(); i++) {
			 sub.push_back(s[i]);
			 DFS(s, i + 1, res, sub);
			 sub.pop_back();
		 }
	 }
};