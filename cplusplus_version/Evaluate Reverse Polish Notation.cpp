class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it;
    	vector<string> temp;
    	int result = 0;
    	if( 0 == tokens.size() ) {
    		return 0;
    	}
    	while(true) {
    		if( 1 == tokens.size()) {
    			return atoi(tokens[0].c_str());
    		}
    		temp.clear();
    		for(size_t i=0; i<tokens.size(); i++) {
    			if(i+2<tokens.size()) {
    				bool i_str = tokens[i].length() != 1 || isdigit(tokens[i][0]);
    				bool i1_str = tokens[i+1].length() != 1 || isdigit(tokens[i+1][0]);
    				bool operate = tokens[i+2].length() == 1 && !isdigit(tokens[i+2][0]);
    				if(i_str && i1_str && operate) {
    					int one = atoi(tokens[i].c_str());
    					int two  = atoi(tokens[i+1].c_str());
    					switch(tokens[i+2][0])
    					{
    						case '+':result = one + two;break;
    						case '-':result = one - two;break;
    						case '*':result = one * two;break;
    						case '/':result = one / two;break;
    						default:
    							cout<<"error occured"<<endl;
    
    					}
    					stringstream strStream;
    					strStream<<result;
    					temp.push_back(strStream.str());
    					i = i + 2;
    				} else {
    					temp.push_back(tokens[i]);
    				}
    			} else {
    				temp.push_back(tokens[i]);
    			}
    		}
    		tokens.clear();
    		for(it= temp.begin(); it !=temp.end(); it++) {
    			tokens.push_back(*it);
    		}
    	}
    }
};

/**
 * another time doing it
 */
/*

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

 */