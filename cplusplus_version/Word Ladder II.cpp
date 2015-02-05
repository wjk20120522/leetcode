class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		
		unordered_map<string, int> dis;
		vector<vector<string> > res;
		vector<string> onepath;

		if (start == end) {
			onepath.push_back(start);
			res.push_back(onepath); return res;
		}
		
		
		stack<string> q;
		dict.insert(end);
		dis[start] = 1;
		q.push(start);
		
		vector<string> v;
		v.push_back(start);


		/*
		create a dictionary to store alphabet used
		*/
		int i, j;
		vector< vector<char> > alpha(end.size());
		for (string str : dict) {
			for (i = 0; i < str.length(); i++) {

				for (j = 0; j < alpha[i].size(); j++) {
					if (alpha[i][j] == str[i]) break;
				}
				if (j == alpha[i].size())
					alpha[i].push_back(str[i]);
			}
		}
		int min = INT_MAX;
		getPath(dis, res, end, v, dict, start, min, alpha);
	
		return res;
	}

	void getPath(unordered_map<string, int> &dis, vector<vector<string> >& res,
		string& end, vector<string>& v, unordered_set<string> &dict, string& cur, int& min,
		vector< vector<char> >& alpha) {
	
			if (cur == end) {
				if (dis[cur] <= min) {
					if (dis[cur] < min) {
						res.clear();
						min = dis[cur];
					}
					res.push_back(v);
				}
				return;
			}

			

			
			for (int i = 0; i < cur.length(); i++) {
				string tmp = cur;
				for (int j = 0; j<alpha[i].size(); j++) {
					tmp[i] = alpha[i][j];
				/*for (char c = 'a'; c <= 'z'; c++) {
					tmp[i] = c;*/

					if (dict.find(tmp) != dict.end() && ( dis.find(tmp) == dis.end()  || dis[tmp] > dis[cur] )     ) {
						dis[tmp] = dis[cur] + 1;
						v.push_back(tmp);
						getPath(dis, res, end, v, dict, tmp, min, alpha);
						v.pop_back();
					}
				}
			} // end for	
	}
};