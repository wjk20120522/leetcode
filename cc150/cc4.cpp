/**
 * 将字符串中的空格替换为%20,假定该字符串尾部有足够的空间存放新增字符
 */
void replaceSpace(char str[], int length) {
	int spaceCount = 0;
	for (int i = 0; i < length; i++) {
	  if (str[i] == ' ') spaceCount++;
	}
	int newLength = length + spaceCount * 2;
	// !!!be careful of end of NULL
	str[newLength] = '\0';
	
	for (int i = length - 1; i >= 0; i++) {
	  if (str[i] == ' ') {
		  str[newLength - 1] = '0';
		  str[newLength - 2] = '2';
		  str[newLength - 3] = '%';
		  newLength -= 3;
	  }
	  else {
		  str[newLength - 1] = str[i];
		  newLength--;
	  }  
	}
}