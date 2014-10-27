class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
		
		for (unsigned int i = 0; i < s.length(); i++)
		{
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			{
				st.push(s[i]);
			}
			else
			{
				switch (s[i])
				{
				case ']':
					if ( st.empty() || st.top() != '[' )
						return false;
					break;
				case ')':
					if ( st.empty() || st.top() != '(' )
						return false;
					break;
				case '}':
					if ( st.empty() || st.top() != '{' )
						return false;
					
					break;
				default:
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) 
			return false;
		return true;
    }
};