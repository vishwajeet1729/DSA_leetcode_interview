// Last updated: 1/17/2026, 12:34:58 PM
class Solution {
public:
    bool isMatch(string s1, string s2) {
      unordered_map<string,int>m;
    function<bool(int,int)>rec=[&](int ind1,int ind2)->bool{
        if(ind1==s1.size()&&ind2==s2.size())return 1;
        if(s1.size()==ind1)
        {
        while(ind2<s2.size()&&s2[ind2]=='*')ind2++;return ind2==s2.size();}      
        string key=to_string(ind1)+","+to_string(ind2);
        if(m.count(key))return m[key];
         int ans=0;
         if(s1[ind1]==s2[ind2]||s2[ind2]=='?')ans=rec(ind1+1,ind2+1);
         else if(s2[ind2]=='*')ans=rec(ind1,ind2+1)|rec(ind1+1,ind2);
           else ans=0;
           return m[key]=ans;
    };
    return rec(0,0);
    }
};