class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
		string tmp;
		int count, len;
		for (int i = 2; i <= n; i++)
		{
			tmp = "";
			len = res.size();
			for (int j = 0; j<len; j++)
			{
				if (j == len - 1)
				{
					tmp += "1";
					tmp += res[len - 1];
					//tmp += "1" + res[len - 1];
					break;
				}
				count = 1;
				while (res[j] == res[j + 1] && j<len - 1)
				{
					j++;
					count++;
				}
				stringstream ss;
				ss << count;
				tmp += ss.str();
				tmp += res[j];

			}

			res = tmp;
		}
		return res;
    }
};