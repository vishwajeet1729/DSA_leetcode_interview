class Solution {
public:
    int numDistinct(string s1, string s2) {
        unordered_map<string,int>m;
     function<int(int,int)>rec=[&](int ind1,int ind2)->int{
        if(ind2==s2.size())return 1;   
      if(ind1==s1.size())return 0;
    string key=to_string(ind1)+","+to_string(ind2);
    if(m.count(key))return m[key];
      int ans=0;
      if(s1[ind1]==s2[ind2])ans=rec(ind1+1,ind2+1)+rec(ind1+1,ind2);
      else ans=rec(ind1+1,ind2);
      return m[key]=ans;
     };
  return rec(0,0);
    }
};