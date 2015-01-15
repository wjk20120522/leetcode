/*
确定一个字符串是否所有字符全都不同。 假若不允许使用额外的数据结构，又该如何处理
*/

// 解法1， 假设字符最多是256个  O(n)  O(1)
bool isUniqueChars(string str) {
	bool charset[256];
	for(int i=0; i<256; i++) {
		charset[i] = false;
	}

	for(int i=0; i<str.length(); i++) {
		if(charset[i]) return false;
		charset[i] = true;
	}
	return true;
}
//改进 改用位向量，减少空间为原来1/8
bool isUniqueChars2(string str) {
	bitset<256>b;
	b.reset();
	for(int i=0; i<str.length(); i++) {
		if(b.test(i)) return false;
		b.set(i);
	}
}
