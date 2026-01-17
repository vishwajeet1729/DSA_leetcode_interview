// Last updated: 1/17/2026, 12:30:57 PM
class Solution {
public:
    int minInsertions(string s) {
          map<string,int>m;
      function<int(int,int)>rec=[&](int x,int y)->int{
        if(x>=y)return 0;
        string key=to_string(x)+"|"+to_string(y);
        if(m.find(key)!=m.end())return m[key];
        int ct=0;
        if(s[x]==s[y])  ct=rec(x+1,y-1);
        else  ct=1+min(rec(x+1,y),rec(x,y-1));
        return m[key]=ct; 
      };
      return rec(0,s.size()-1); 
    }
};