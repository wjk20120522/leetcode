class Solution {
public:
    string convert(string s, int nRows) {
        if (s.length() == 0 || nRows <= 0) return "";
		if (nRows == 1) return s;
		string res = s;
		int nums = 2 * nRows - 2;
		int index = 0;
		for (int i = 0; i<nRows; i++)
		{
			for (int j = i; j<s.length(); j += nums)
			{
				res[index++] = s[j];
				if (i != 0 && i != nRows-1 && j + nums - 2 * i<s.length())
				{
					res[index++] = s[j + nums - 2 * i];
				}
			}
		}
		return res;
    }
};