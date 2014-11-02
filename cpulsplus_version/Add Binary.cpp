string res = "";
		int len1 = a.length();
		int len2 = b.length();

		int end1 = len1 - 1;
		int end2 = len2 - 1;
		
		int tmp;
		int digit = 0;
		while (end1 >= 0 && end2 >= 0)
		{
			tmp = a[end1] - '0' + b[end2] - '0' + digit;
			if (tmp >= 2)
			{
				digit = 1;

			}
			else
			{
				digit = 0;
			}
			stringstream ss;
			ss << (tmp % 2);
			res += ss.str();
			end1--; end2--;
		}

		while (end1 >= 0)
		{
			tmp = a[end1] - '0' + digit;
			if (tmp >= 2)
			{
				digit = 1;
			}
			else
			{
				digit = 0;
			}
			stringstream ss;
			ss << (tmp % 2);
			res += ss.str();
			end1--;
		}
		while (end2 >= 0)
		{
			tmp = b[end2] - '0' + digit;
			if (tmp >= 2)
			{
				digit = 1;

			}
			else
			{
				digit = 0;
			}
			stringstream ss;
			ss << (tmp % 2);
			res += ss.str();
			end2--;
		}
		if (digit == 1)
		{
			stringstream ss;
			ss << digit;
			res += ss.str();
		}

		int first = 0, last = res.length() - 1;

		while (first < last)
		{
			char tmp = res[first];
			res[first] = res[last];
			res[last] = tmp;
			first++; last--;
		}
		return res;