class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
     
        vector<string> dumpstrs = strs;
		vector<string> res;
		unordered_map < string, vector<int> > map;

		for (unsigned int i = 0; i < dumpstrs.size(); i++) {
		  sort(dumpstrs[i].begin(), dumpstrs[i].end());
		  //把对应的标号存入
		  map[dumpstrs[i]].push_back(i);
		}
		for (auto it = map.begin(); it != map.end(); it++) {
		  if (it->second.size() > 1) {
			  for (unsigned int i = 0; i < it->second.size(); i++) {
				  res.push_back(strs[it->second[i]]);
			  }
			 
		  }
		}
		return res;
    }
};


/*
two times of sort
 */
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, int> mp;
		vector<string> res;
		for (string str : strs) {
			sort(str.begin(), str.end());
			mp[str]++;
		}
		for (string str : strs) {
			string tmp = str;
			sort(str.begin(), str.end());
			if (mp[str] > 1) {
				res.push_back(tmp);
			}
		}
		return res;
    }
};
