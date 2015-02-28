/*
easy to understand
 */
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		rowIndex++;
		vector<int> res, pre;
		for (int i = 1; i <= rowIndex; i++) {
			//generate each line
			res.clear();
			for (int j = 0; j < i; j++) {
				if (j == 0 || j == i - 1) {
					res.push_back(1);
				}
				else {
					res.push_back(pre[j - 1] + pre[j]);
				}
			}
			pre = res;
		}
		return res;
	}
};


/*
short code
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1, 1);
        for(int i=2; i<=rowIndex; i++)
        {
            for(int j=i-1; j>=1; j--)
            {
                v[j] = v[j] + v[j-1];
            }
        }
        return v;
    }
};