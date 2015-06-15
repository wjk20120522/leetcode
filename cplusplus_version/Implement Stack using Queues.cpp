class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q.size() > 1) {
            swap.push(q.front());
            q.pop();
        }
        q.pop();
        q.swap(swap);
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.size() == 0;
    }

private:
    queue<int> q,swap;
};