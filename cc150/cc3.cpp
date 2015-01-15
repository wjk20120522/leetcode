/**
 * 给定两个字符串，确定其中一个字符串重新排列后，可以变成另一个字符串
 */

//解法1，两个字符串排序后比较是否相等,比较实用
 bool permutation(string s, string t) {
	  if (s.length() == 0 || t.length() == 0 || s.length() != t.length()) return false;
	  sort(&s[0], &s[0] + s.length());
	  sort(&t[0], &t[0] + t.length());
	  return s == t;
  }

//解法2， 判断两个字符串字符数目是否相同
bool permutation(string s, string t) {
	if (s.length() == 0 || t.length() == 0 || s.length() != t.length()) return false;
	int charset[256];   //假设字符集为ASCII
	memset(charset, 0, sizeof(charset));
	for (char c : s) {
	  charset[c]++;
	}
	for (char c : t) {
	  if (--charset[c] < 0) return false;
	}
	return true;
}