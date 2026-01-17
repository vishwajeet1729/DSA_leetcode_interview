// Last updated: 1/17/2026, 12:33:50 PM
class Solution {
public:
    int evalRPN(vector<string>& token) {
           stack<int>s;

           for(int i=0;i<token.size();++i){
               if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (token[i] == "+") s.push(a + b);
                else if (token[i] == "-") s.push(a - b);
                else if (token[i] == "*") s.push(a * b);
                else s.push(a / b); 
               }
            else 
                s.push(stoi(token[i]));  
               }
               return s.top();

    }
};