class Solution {
public:
    int compareVersion(string version1, string version2) {
       int i=0, j=0;
		  string str1="0", str2="0";
		  while (i < version1.size() || j < version2.size()) {
			  while (str1.back() != '.' && i < version1.size()) str1 += version1[i++];
			  while (str2.back() != '.' && j < version2.size()) str2 += version2[j++];

			  if (stoi(str1) > stoi(str2)) return 1;
			  else if (stoi(str1) < stoi(str2)) return -1;

			  str1 = "0", str2 = "0";
		  }
		  return 0;
    }
};


/*
same idea, but use int to save the two tmp chilid version
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
		int count1 = 0, count2 = 0;
		for (int i = 0, j=0; i < len1 || j < len2; i++,j++) {
			while (i < len1 && version1[i] != '.') {
				count1 = count1 * 10 + version1[i] - '0';
				i++;
			}
			while (j < len2 && version2[j] != '.') {
				count2 = count2 * 10 + version2[j] - '0';
				j++;
			}
			if (count1 > count2) return 1;
			if (count1 < count2) return -1;
			count1 = 0, count2 = 0;
		}
		return 0;
    }
};