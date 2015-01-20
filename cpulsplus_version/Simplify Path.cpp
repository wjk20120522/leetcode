 class Solution {
 public:
	 string simplifyPath(string path) {
		 vector<string> s;
		 string file;
		 s.push_back("/");

		 for (unsigned int i = 0; i < path.length(); i++) {
			 if (path[i] == '/') {
				 if (file.size() == 0) {
					 continue;
				 }
				 if (file == ".") {

				 }
				 else if (file == "..") {
					 if (s.size() >1) s.pop_back();
				 }
				 else {
					 s.push_back(file);
				 }
				 file.clear();
			 }
			 else {
				 file.push_back(path[i]);          //files
			 }
		 }
		 // the last file 
		 if (file.size() != 0) {
			 if (file == ".") {

			 }
			 else if (file == "..") {
				 if (s.size() >1) s.pop_back();
			 } else 
				s.push_back(file);
		 }
		 string res ;
		 if (s.size() == 1) return "/";
		 for (unsigned int i = 1; i < s.size(); i++) {
			 res += "/" + s[i];
		 }
		 return res;
	 }
 };