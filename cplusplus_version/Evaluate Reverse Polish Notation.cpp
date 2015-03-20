class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
          int res = 0;
          string tmp;
          for (int i = 0; i < tokens.size(); i++) {
              tmp = tokens[i];
              if (!isdigit(tmp[0]) && tmp.size() == 1) { // operators, be careful about -4 and -
                  int one = s.top(); s.pop();
                  int two = s.top(); s.pop();
                  switch (tmp[0])
                  {
                  case '+':
                      s.push(two + one); break;
                  case '-':
                      s.push(two - one); break;
                  case '/':
                      s.push(two / one); break;
                  case '*':
                      s.push(two * one); break;
                  default:
                      break;
                  }
              }
              else {
                  s.push(stoi(tmp));            //operand
              }
          }
          return s.top();
    }
};
