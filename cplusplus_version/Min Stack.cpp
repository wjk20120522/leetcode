class MinStack {
  public:
	  stack<int> s;
	  stack<int> min;

	  void push(int x) {
		  s.push(x);
		  if (min.empty() || min.top() >= x) {
			  min.push(x);
		  }
	  }

	  void pop() {
		  if (s.top() == min.top()) {
			  min.pop();
		  }
		  s.pop();
	  }

	  int top() {
		  return s.top();
	  }

	  int getMin() {
		  return min.top();
	  }
};