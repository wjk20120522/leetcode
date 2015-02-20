/*
use one stack to save the min element and another stack performs normal push,pop,top...
 */
class MinStack {
public:
	void push(int x) {
		if (min.empty() || min.top() >= x) {
			min.push(x);
		}
		st.push(x);
	}

	void pop() {
		if (st.top() == min.top()) min.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int>min;
	stack<int>st;
};