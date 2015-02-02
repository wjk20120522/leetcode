class Solution {
public:
	int candy(vector<int> &ratings) {
		if (ratings.size() <= 1) {
			return ratings.size();
		}
		vector<int>candy(ratings);

		/*
		Pay attention to the equals between neighbors
		 */
		for (int i = 0; i < ratings.size(); i++) {
			
			if (i == ratings.size() - 1) {              // the last one
				if (ratings[i] > ratings[i - 1])
					candy[i] = candy[i - 1] + 1;
				else {
					candy[i] = 1;
				}
			}
			else {
				// if no decending
				if (i>0 && ratings[i] > ratings[i - 1] && ratings[i] <= ratings[i+1])
					candy[i] = candy[i - 1] + 1;
				else if (i>0 && ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
					candy[i] = 1;
				else {
					// decending
					int cur = i;
					int rightsmaller = 0;
					while (i < ratings.size() - 1 && ratings[i] > ratings[i+1]) {
						i++; rightsmaller++;
					}
					if (cur == 0) {
						candy[cur] = rightsmaller + 1;
					}
					else {
						if (ratings[cur] > ratings[cur - 1]) {
							candy[cur] = candy[cur - 1] > rightsmaller ? candy[cur - 1] + 1 : rightsmaller + 1;
						}
						else if (ratings[cur] == ratings[cur - 1]) {
							candy[cur] = rightsmaller + 1;
						}
					}

					while (rightsmaller) {
						candy[++cur] = rightsmaller;
						rightsmaller--;

					}


				}
			}
		
		}

		//calculate 
		int res = 0;
		for (int i = 0; i < candy.size(); i++) {
			res += candy[i];
		}
		return res;

	}
};

/**
 * more beautiful code below
 */

/*

class Solution {
public:
	int candy(vector<int> &ratings) {
		int size = ratings.size();
		if (size <= 1) {
			return size;
		}

		vector<int>candy(size, 1);
		//	main idea: calculate small-big, then calculate small-big in reverse order
		
		for (unsigned int i = 1; i < size; i++){
			if (ratings[i] > ratings[i - 1]) {
				candy[i] = candy[i-1] + 1;
			}
		}
		for (unsigned int i = size - 1; i > 0; i--) {
			if (ratings[i - 1] > ratings[i]) {
				candy[i - 1] = candy[i - 1] > candy[i] + 1 ? candy[i - 1] : candy[i] + 1;
			}
		}
		return accumulate(candy.begin(), candy.end(), 0);
	}
	
};
 */