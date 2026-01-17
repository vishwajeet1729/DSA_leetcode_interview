// Last updated: 1/17/2026, 12:29:24 PM
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& v) {
          stack<unsigned long long>s;
int n=v.size();
    for(int i=0;i<n;++i){
          
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        unsigned long long cur=v[i];
        while(!s.empty() && (__gcd(cur, s.top())) > 1){
    cur = (cur*s.top())/__gcd(cur, s.top());
    s.pop();
}

        s.push(cur);
    }

    // cout<<"kk";
    vector<int>ans;
    while(!s.empty()){
       //   cout<<s.top()<<endl;
          ans.push_back(s.top());
      s.pop();  
    }
    reverse(ans.begin(),ans.end());
    return ans;


    }
};