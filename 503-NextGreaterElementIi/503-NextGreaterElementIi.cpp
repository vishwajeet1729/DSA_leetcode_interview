// Last updated: 1/17/2026, 12:32:37 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
            int n=v.size();
            vector<int>ans(n);
            stack<int>s;
            for(int i=2*n-1;i>=0;--i){
                 
                while(!s.empty()&&v[i%n]>=v[s.top()])s.pop();
                   ans[i%n]=s.empty()?-1:v[s.top()];
                   s.push(i%n);
            }
            return ans;

    }
};