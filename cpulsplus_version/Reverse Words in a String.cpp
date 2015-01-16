#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int begin = 0,end = 0;
		int i,j;
		bool first = true;
		string temp = "";
		for(i=0; i<s.length(); i++) {
			if(s[i] != ' ' && first) {
				first = false;
				begin = i;
				end = i;
			}
			if(s[i] != ' ') {
				end = i;
			}
		}
		if(!first) {
			temp = s.substr(begin,end-begin+1);
		}
		for(i=0,j=temp.length()-1; i<j; i++,j--) {
			swap(temp[i],temp[j]);
		}
		first = true;
		s = "";
		for(i=0; i<temp.length(); i++)
		{
			while(i<temp.length() && temp[i] == ' ' ) {
				i++;
			}
			begin = i;
			while(i<temp.length() && temp[i] != ' ' ) {
				i++;
			}
			end = i-1;
			if(!first) {
				s += " ";
			}
			else {
				first = false;
			}
			int temp_begin = begin, temp_end = end;
			while(temp_begin < temp_end) {
				swap(temp[temp_begin], temp[temp_end]);
				temp_begin++; temp_end--;
			}
			s += temp.substr(begin,end-begin+1);
		}
	
    }
};

int main() {

        Solution s;
        string str = "  hq lv   wjk ";
        s.reverseWords(str);
        return 0;
}

/**
 * second time doing it
 */

/*

class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
		  reverse(s.begin(), s.end());
		  int prevSpace = 0;
		  bool first = true;
		  string res;
		  for (unsigned int i = 0; i < s.length(); i++) {
			  if (s[i] == ' ') {

				  reverse(&s[prevSpace], &s[i]);
				  
				  if (first && prevSpace != i) {
					  first = false;
				  }
				  else {
					  res += ' ';
				  }
				  res += s.substr(prevSpace, i - prevSpace);
				  i++;
				  while (i < s.length() && s[i] == ' ') i++;
				  prevSpace = i;
			  }
			  
			 
		  }
		  if (prevSpace <= s.length() - 1) {
		      if (!first)   res += ' ';
			  reverse(&s[prevSpace], &s[s.length()]);
			  res += s.substr(prevSpace, s.length() - 1 - prevSpace +1);
		  }
		  s = res;
		  
		  int i = 0;
		  while (s[i] == ' ') i++;
		  s = s.substr(i);
		  int j = s.length() - 1;
		  while (j >= 0 && s[j] == ' ') {
			  j--;
		  }
		  s = s.substr(0, j+1);
    }
};

 */