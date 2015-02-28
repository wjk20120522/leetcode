class Solution {
 public:
	 vector<vector<int> > generate(int numRows) {
		 vector<vector<int> > res;
		 vector<int> tmp;
		 for (int i = 1; i <= numRows; i++) {
			 tmp.clear();
			 // generate one line
			 for (int j = 0; j < i; j++) {
				 if (j == 0 || j == i - 1) {
					 tmp.push_back(1);
				 }
				 else {
					 tmp.push_back(res[i - 2][j - 1] + res[i - 2][j]);
				 }
			 }
			 res.push_back(tmp);
		 }
		 return res;

	 }
 };