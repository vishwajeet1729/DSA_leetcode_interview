// Last updated: 1/17/2026, 12:31:18 PM
class Solution {
public:
  
  int apply(int a, int b, char op) {
        switch (op) {
        case '&':
            return a & b;
        case '|':
            return a | b;
        case '^':
            return a ^ b;
        case '!':
            return !a;
        case '<':
            return a << b;
        case '>':
            return a >> b;
        default:
            return 0;
        }
    }
    bool parseBoolExpr(string exp) {

        stack<char> st;
        int ans = -1;
        // for (int i = 0; i < exp.size(); ++i)
            // (exp[i] == 'f') ? exp[i] = '0' : exp[i] = '1';
        for (int i = 0; i < exp.size(); ++i) {
            ans=-1;
            if (exp[i] == ')') {
                string s = "";
                while (st.top() != '(') {
                    char c = st.top();
                    if (c != ',') {
                        if (c == 'f')
                            s += '0';
                        else
                            s += '1';
                        //    else s[i]+=c;
                    }
                    st.pop();
                }
                // cout<<s<<endl;
                st.pop();
                char ops = st.top();
                st.pop();
                // cout<<ops<<endl;
                for (int i = 0; i < s.size(); ++i) {
                    if (ans != -1)
             ans = apply(ans, s[i] - '0', ops);

                    else
                       { ans = s[i] - '0';
                        ans = apply(ans, s[i] - '0', ops);
                       }
                }
                // cout<<"ans is the  : "<<ans<<endl;
                if(ans==0)st.push('f');
                else st.push('t');
                // st.push(ans+'0');

            } else
                st.push(exp[i]);
        }
        return ans;
    }



};

