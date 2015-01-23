class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		 if (s1.length() == 0 || s2.length() == 0) return s3 == s1 + s2;
		 vector<int>v2(s2.length(), 0);
		 vector< vector<int> >v1;
		 for (unsigned int i = 0; i < s1.length(); i++)
			 v1.push_back(v2);
		

		 return compare(s1, s1.length() - 1, s2, s2.length() - 1, s3, s3.length() - 1, v1);
		 
	 }

	 bool compare(string s1, int i1, string s2, int i2, string s3, int i3, vector< vector<int> >&v) {
		 if (i3 == -1 && i1== -1 && i2 == -1) return true;
		 if (i1>=0 && i2>=0 && v[i1][i2] == 1) return true;
		 if (i1 >= 0 && i2 >= 0 &&  v[i1][i2] == -1) return false;
		 bool s11 = false, s22 = false;
	 
		 if (i1 >= 0 && s1[i1] == s3[i3]) {
			 s11 = compare(s1, i1 - 1, s2, i2, s3, i3 - 1, v);
			 if ( i1 > 0 && i2 >= 0) {
				 if (s11) v[i1 - 1][i2] = 1;
				 else v[i1 - 1][i2] = -1;
			 }
		 }
			
		 if (i2 >= 0 && s2[i2] == s3[i3]) {
			 s22 = compare(s1, i1, s2, i2 - 1, s3, i3 - 1, v);
			 if ( i1 >= 0 && i2 > 0) {
				 if (s22) v[i1][i2 - 1] = 1;
				 else v[i1][i2 - 1] = -1;
				
			 }	
		 }
			 
		 if (s11 || s22) {
			 return true;
		 }
		 return false;
	 }
};