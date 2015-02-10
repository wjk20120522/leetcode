class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int max = 0;
		vector<int> v;
		height.push_back(0);
		for (int i = 0; i <= height.size(); i++) {
			while (!v.empty() && height[v.back()] >= height[i]) {
				int h = height[v.back()];
				v.pop_back();

				int idx = v.empty() ? -1 : v.back();

				if ((i - 1 - idx) * h > max) {
					max = (i - 1 - idx)*h;
				}
			}
			v.push_back(i);
		}
		return max;
	}
};