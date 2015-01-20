class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> res;
		 for (auto i : num) {
			 res.push_back(to_string(i));
		 }

		 sort(res.begin(), res.end(), [](string& s1, string& s2) {return s1 + s2 > s2 + s1; });

		 string out; 
		 for (auto str : res) {
			 out += str;
		 }
		 if (out[0] == '0' || out == "") return "0";
		 return out;
        
    }
    
};