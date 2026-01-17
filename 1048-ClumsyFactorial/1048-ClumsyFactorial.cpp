// Last updated: 1/17/2026, 12:31:32 PM
class Solution {
public:

    int clumsy(int n) {
        stack<int>st;
        st.push(n);
        int t = 1;
        for(int i=n-1; i>0; i--){
            int x = st.top();
            if(t==1){
                st.pop();
                st.push(x*i);
                t=2;
                continue;
            }
            else if(t==2){
                st.pop();
                st.push(x/i);
                t=3;
                continue;

            }
            else if(t==3){
                st.pop();
                st.push(x+i);
                t=4;
                continue;
            }
            else if(t==4){
                st.push(-1*i);
                t=1;
            }
        }

        int ans =0;
        while(!st.empty()){
            cout<<st.top()<<" ";
            ans += st.top();
            st.pop();
        }
        cout<<ans<<" ";
        return ans;
    }
};