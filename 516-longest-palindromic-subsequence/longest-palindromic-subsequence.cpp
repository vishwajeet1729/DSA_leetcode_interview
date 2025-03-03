class Solution {
public:
    int longestPalindromeSubseq(string s) {
       unordered_map<string,int>m;

          function<int(int,int)>rec=[&](int x,int y)->int{
             if(x>y)return 0;
             if(x==y)return 1;       
      string key=to_string(x)+"|"+to_string(y);
       if(m.find(key)!=m.end())return m[key];
             int ans=0;       
             if(s[x]==s[y]) ans= 2+rec(x+1,y-1);
             
             else ans=max(rec(x+1,y),rec(x,y-1));
             return m[key]=ans;

          };

        //   cout<<rec(0,s.size()-1)<<endl;
        return rec(0,s.size()-1);    
    }
};