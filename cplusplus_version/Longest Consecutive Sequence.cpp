class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int>mp;
		 int res = 0;
		 for (int n : num) {
			 if (mp[n]) continue;   // has appear
			 mp[n] = mp[n - 1] + mp[n + 1] + 1;
			 // we don't care about middle between n-mp[n-1] and n+mp[n+1]
			 mp[n - mp[n - 1]] = mp[n];      //left most must be set
			 mp[n + mp[n + 1]] = mp[n];      //rigth most must be set

			 res = res > mp[n] ? res : mp[n];
		 }
		 return res;
    }
};