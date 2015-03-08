class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesis(n, n, res, "");
		return res;
	}

	void generateParenthesis(int left, int right, vector<string>&res, string tmp) {
		if (left == 0 && right == 0) {
			res.push_back(tmp); return;
		}
		if (left > 0) {
			generateParenthesis(left - 1, right, res, tmp + "(");
		}
		if (right > left) {
			generateParenthesis(left, right - 1, res,  tmp + ")");
		}
	}
};


/*
short but cost more time
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string>(1,"") ;
        if(n==1) return vector<string>(1,"()") ;
        vector<string> result;
        for(int i=0;i!=n;i++)
            for(auto inner: generateParenthesis(i))
                for(auto outter:  generateParenthesis(n-i-1))
                    result.push_back("("+inner+")"+outter);
        return result;
    }
};