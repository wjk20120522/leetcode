class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		unordered_map<string, int> dis;    // use this to store the distance between start to the word
		if (start.length() == 0) return 0;
		if (start == end) return 1; 
		queue<string> q;
		dis[start] = 1;
		q.push(start);
		while (!q.empty()) {
			string cur = q.front(); q.pop();
			if (cur == end) break;
			for (int i = 0; i < cur.length(); i++) {
				string tmp = cur;
				for (char c = 'a'; c <= 'z'; c++) {					  
					tmp[i] = c;
					// this tmp is in the dict but not introduced into dis
					if (dict.find(tmp) != dict.end() && dis.find(tmp) == dis.end()) {
						dis[tmp] = dis[cur] + 1;
						q.push(tmp);
					}
				}
			}
		}
		if (dis.find(end) == dis.end()) return 0;
		else return dis[end];
    }
};

/*
use int res instead of unordered_map, less time
 */
class Solution {
 public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int res = 1;
		queue<string> q;
		q.push(start); q.push("");
		while (!q.empty()) {
			string cur = q.front(); q.pop();
			if (cur != "") {
				for (int i = 0; i < cur.length(); i++) {
					string tmp = cur;
					for (char c = 'a'; c <= 'z'; c++) {
						tmp[i] = c;
						if (tmp == end) return res + 1;
						// this tmp is in the dict but not introduced into dis
						if (dict.find(tmp) != dict.end()) {
							q.push(tmp);
							dict.erase(tmp);
						}
					}
				}
			}
			else if(!q.empty()){
				res++; q.push("");
			}
		}
		return 0;
	}
};