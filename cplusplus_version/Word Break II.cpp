class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector< string >res;
		if (dict.size() == 0)  return res;
		vector< vector<int> > spaceInd(s.size()+1);
		spaceInd[0].push_back(-1);

		// 将合适的分词位置保存
		for (unsigned int i = 1; i <= s.size(); i++) {
			for (unsigned int j = 0; j < i; j++) {
				if (spaceInd[j].size() && dict.count(s.substr(j,i-j))) {
					spaceInd[i].push_back(j);
				}
			}
		}

		return backTrack(s, spaceInd, s.size());

	}

	vector<string> backTrack(string&s, vector< vector<int> >& spaceInd, int idx) {
		vector<string> res;
		if (idx <= 0) {
			res.push_back(""); return res;
		}

		for (unsigned int i = 0; i < spaceInd[idx].size(); i++) {
			string str = s.substr(spaceInd[idx][i], idx - spaceInd[idx][i]);  // 取合格的sub string
			vector<string> subRes = backTrack(s, spaceInd, spaceInd[idx][i]);

			for (unsigned int j = 0; j < subRes.size(); j++) {
				if (subRes[j] != "") {
					subRes[j] = subRes[j] + " " + str;
				}
				else {
					subRes[j] = str;
				}
				res.push_back(subRes[j]);
			}
		}
		return res;
	}

};
