// Last updated: 1/17/2026, 12:34:37 PM
class Solution {
public:
    int minDistance(string s1, string s2) {
        unordered_map<string,int>m;
        function<int(int,int)>rec=[&](int ind1,int ind2)->int{
        if(ind1==s1.size()||ind2==s2.size())return s1.size()-ind1+s2.size()-ind2;  
        string key=to_string(ind1)+","+to_string(ind2);
        if(m.count(key))return m[key];
        int ans=0;
        if(s1[ind1]==s2[ind2])ans=rec(ind1+1,ind2+1);
        else ans=1+min({rec(ind1,ind2+1),rec(ind1+1,ind2),rec(ind1+1,ind2+1)});
         return m[key]=ans;
      };
       return rec(0,0);
    }
};