 class Solution {
 public:
	 vector<string> restoreIpAddresses(string s) {
		 vector<string> res;
		 int len = s.length();
		 if (len <4 || len >12) return res;  // be careful if length is too large stoi will erupt
		 for (int i = 1; i < 4 && i < len; i++) {    // make sure i <len-2 because of substr exception
			 for (int j = 1; j < 4 && i + j < len; j++) {
				 for (int k = 1; k < 4 && i + j + k < len; k++) {
					 string s1 = s.substr(0, i); string s2 = s.substr(i, j); 
					 string s3 = s.substr(i + j, k); string s4 = s.substr(i + j + k, len - i - j - k);
					 if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
						 res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
					 }
				 }
			 }
		 }
		 return res;
	 }

	 bool isValid(string s) {
		 if (  (s.length() > 1 && s[0] == '0') || stoi(s) > 255 ) 
			 return false;
		 return true;
	 }
 };