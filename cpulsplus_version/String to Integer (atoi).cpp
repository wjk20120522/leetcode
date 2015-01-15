class Solution {
public:
	int atoi(const char *str) {
		if (str == NULL) return 0;
		long long int res = 0, i;
		bool negative = false;
		bool bad_characters = false;
		for (i = 0; str[i] != '\0' && str[i] == ' '; i++)
			//only white space
		if (str[i] == '\0') return 0;
		
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')   negative = true;
			i++;
		}
		//the first character is not valid numbers
		if (str[i] != '\0' && (str[i] <'0' || str[i]>'9')) return 0;
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				if (!negative && res >= INT_MAX)
				{
					return INT_MAX;
				}
				if (negative && res >= INT_MAX+1)
				{
					return INT_MIN;
				}
				
			}
			else
			{
				if (negative) return -res;
				return res;
			}
			i++;
		}

		if (negative) return -res;
		return res;

	}
};