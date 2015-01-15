/*
用C/C++实现void reverse(char *str)函数，即反转以NULL结尾的字符串
*/

void reverse(char *str) {
	if(str == NULL) return;
	char *begin = str;
	char *end = str;
	while(*end) end++;
	end--;
	while(begin < end) {
		swap(*begin, *end);
	}
}